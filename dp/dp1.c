#include <stdio.h>
#include <stdlib.h>
#include<semaphore.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void print(int id,int state);


 sem_t mutex[6];

void phillos(int id)
{
    int state=0;
    printf("id %d pid %d\n",id,getpid());
   
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
		sem_wait(&mutex[(id+1)]);
                //semaphore_p(sem_id[(id+1)]);
                state=2;
		print(id,state);
                sleep(rand()%3);
           //     sem_post(&mutex[(id+1)]);
            }
            else if(id==4)
            {
		sem_wait(&mutex[(id)]);
               // semaphore_p(sem_id[id]);
                state=2;
                print(id,state);
                sleep(rand()%3);
           // sem_post(&mutex[(id)]);
            }
            else if(id==2)
            {
sem_wait(&mutex[(id+1)]);
sem_wait(&mutex[(id)]);
              //  semaphore_p(sem_id[id+1]);
               // semaphore_p(sem_id[(id)]);
                state=2;
                print(id,state);
                sleep(rand()%3);
//sem_post(&mutex[(id)]);
//sem_post(&mutex[(id+1)]);
            }
            else
            {
sem_wait(&mutex[(id)]);
sem_wait(&mutex[(id+1)]);
               // semaphore_p(sem_id[(id)]);
               // semaphore_p(sem_id[id+1]);
                state=2;
                print(id,state);
                sleep(rand()%3);
//sem_post(&mutex[(id+1)]);
//sem_post(&mutex[(id)]);
            }
        }
        else      // state 2
        {
            if(id==0)
            {
//sem_wait(&mutex[(id+1)]);
sem_post(&mutex[(id+1)]);
                //semaphore_v(sem_id[(id+1)]);
                state=0;
                print(id,state);
                sleep(rand()%3);

            }
            else if(id==4)
            {
//sem_wait(&mutex[(id)]);
sem_post(&mutex[(id)]);
               // semaphore_v(sem_id[id]);
                state=0;
                print(id,state);
                sleep(rand()%3);

            }
            else
            {
//sem_wait(&mutex[(id+1)]);
//sem_wait(&mutex[(id)]);

sem_post(&mutex[(id)]);
sem_post(&mutex[(id+1)]);
                //semaphore_v(sem_id[(id+1)]);
                //semaphore_v(sem_id[id]);
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
        printf( "Philosopher  %d is now waiting  \n", id);
    
    }

    else if(state==2)
    {
        printf( "Philosopher  %d is now eating \n", id);
       
    }

    else
    {
        printf( "Philosopher  %d is now thinking \n", id);
       
    }
}



int main()
{
    
    int i=0,pid=0;

   
for(i=0; i<6; i++)
sem_init(&mutex[i],2,1);
    for(i=0; i<5; i++)
    {
        pid=fork();
        if(pid==0)
        {
            //child process
          phillos(i);
printf("child process %d \n" ,i);
            _exit(0);
        }
        else
        {
            // parent process only
printf("parent process %d \n" ,i);
        }
    }
    
//for(i=0; i<6; i++)
//sem_destroy(&mutex[i]);
    while(1);
    return 0;
}
