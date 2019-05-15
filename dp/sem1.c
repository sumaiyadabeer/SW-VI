#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
//#include <types.h>
void print(int id,int state);
int sem_id[6];
char buf[200];
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int semaphore_p(int se_id)//wait
{
    struct sembuf sem_b;
    sem_b.sem_num=0;// number of semaphore in semaphore array
    sem_b.sem_op =-1;// decremented sem value
    sem_b.sem_flg = SEM_UNDO;
    if (semop(se_id, &sem_b, 1) ==-1)
    {
        fprintf(stderr, "failed to get semaphore for philosopher %d in wait %d  pid\n",se_id,getpid());
        return(0);
    }
    return(1);
}

int semaphore_v(int se_id)//signal
{
    struct sembuf sem_b;
    sem_b.sem_num=0;
    sem_b.sem_op =1;
    sem_b.sem_flg = SEM_UNDO;
    if (semop(se_id, &sem_b, 1) ==-1)
    {
        fprintf(stderr, "failed to get semaphore for philosopher in release %d pid %d\n",se_id,getpid());
        return(0);
    }
    return(1);
}

int set_semvalue(int se_id)
{
    union semun sem_union;
    sem_union.val = 1;//available at the begining
    if (semctl(se_id, 0, SETVAL, sem_union) ==-1) return(0);
    return(1);
}

void del_semvalue(int se_id)
{
    union semun sem_union;
    if (semctl(se_id, 0, IPC_RMID, sem_union) ==-1)
        fprintf(stderr, "Failed to delete semaphore\n");
}


void phillos(int id)
{
    int state=0;
    sprintf(buf,"id %d pid %d\n",id,getpid());
    write(1, buf, strlen(buf));
    while(1)
    {
        if(state==0)
        {
            state=1;
            sleep(rand()%3);
	    print(id,state);
        }

        else if(state==1)
        {
            if(id==0)
            {
                semaphore_p(sem_id[(id+1)]);
                state=2;
		print(id,state);
                sleep(rand()%3);
            }
            else if(id==4)
            {
                semaphore_p(sem_id[id]);
                state=2;
                print(id,state);
                sleep(rand()%3);
            }
            else if(id==2)
            {
                semaphore_p(sem_id[id+1]);
                semaphore_p(sem_id[(id)]);
                state=2;
                print(id,state);
                sleep(rand()%3);
            }
            else
            {
                semaphore_p(sem_id[(id)]);
                semaphore_p(sem_id[id+1]);
                state=2;
                print(id,state);
                sleep(rand()%3);
            }
        }
        else
        {
            if(id==0)
            {
                semaphore_v(sem_id[(id+1)]);
                state=0;
                print(id,state);
                sleep(rand()%3);
            }
            else if(id==4)
            {
                semaphore_v(sem_id[id]);
                state=0;
                print(id,state);
                sleep(rand()%3);
            }
            else
            {
                semaphore_v(sem_id[(id+1)]);
                semaphore_v(sem_id[id]);
                state=0;
                print(id,state);
                sleep(rand()%3);
            }
        }
    }
}

void print(int id,int state)
{
    if(state==1)
    {
        sprintf(buf, "Philosopher  %d is now waiting  \n", id);
        write(1, buf, strlen(buf));
    }

    else if(state==2)
    {
        sprintf(buf, "Philosopher  %d is now eating \n", id);
        write(1, buf, strlen(buf));
    }

    else
    {
        sprintf(buf, "Philosopher  %d is now thinking \n", id);
        write(1, buf, strlen(buf));
    }
}

int main()
{
    
    int i=0,pid=0;

    for(i=0; i<6; i++)
    {
        sem_id[i]= semget((key_t)(1233+i),1, 0666 | IPC_CREAT);
        set_semvalue(sem_id[i]);
        sprintf(buf,"%d \n",sem_id[i]);
        write(1,buf,strlen(buf));
    }

    for(i=0; i<5; i++)
    {
        pid=fork();
        if(pid==0)
        {
            //child process
            phillos(i);
            _exit(0);
        }
        else
        {
            // parent process only
        }
    }

    while(1);
    return 0;
}
