#include <stdio.h>
#include <stdlib.h>
#include<semaphore.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */

#include<sys/wait.h>
#include<pthread.h>

sem_t *sem1;
sem_t *sem2;
sem_t *sem3;
 
void print(int id,int state);
 int getm(int j);
int strt, no,k;

 //sem_t mutex[3];
 sem_t cmutex;
 sem_t mutex1;
 sem_t mutex2;
 sem_t mutex3;
 // sem_t *tmutex;
sem_t *sem ;


int pid=0,strt=0;
  int shm;
int i,j=0;
pid_t cpid[6];
char semaphrname[5][5];
char semname[5];




/*void phillos(int id)
{

    int state=0;

    printf("id %d pid %d\n",id,getpid());

   

    while(1)

    { strt++;

	if(state==0)

        {

            state=1;
          
            sleep(rand()%3);

	    print(id,state);

        }else if(state==1)
        {
if(id%2) //odd
{sem_wait(&mutex[((id-1)/2)]);
sem_wait(&cmutex);
}else    //even
{sem_wait(&mutex[(id/2)]);
sem_wait(&cmutex);
}
state=2;
print(id,state);
                
               sleep(rand()%3);
        }else     // state 2
	{
if(id%2) //odd
{sem_post(&mutex[((id-1)/2)]);
sem_post(&cmutex);
}else    //even
{sem_post(&mutex[(id/2)]);
sem_post(&cmutex);
}
state=0;
print(id,state);

                sleep(rand()%3);

	}
printf(" is %d ",strt);      // only work for 6,7,8 dont know why :(((
    }

}*/
void phillos(int id)
{

    int state=0,idd;
id=k;
k++;
    printf("id %d pid %d\n",id,getpid());

   

    while(1)

    { strt++;

	if(state==0)

        {

            state=1;
          
            sleep(rand()%3);

	    print(id,state);

        }else if(state==1)
        {
idd=getm(id);
if(idd==1)
sem_wait(sem1);
if(idd==2)
sem_wait(sem2);
if(idd==3)
sem_wait(sem3);
state=2;
print(id,state);
                
               sleep(rand()%3);
        }else     // state 2
	{
idd=getm(id);
if(idd==1)
sem_post(sem1);
if(idd==2)
sem_post(sem2);
if(idd==3)
sem_post(sem3);

//sem_post(&cmutex);

state=0;
print(id,state);

                sleep(rand()%3);

	}
//printf(" is %d ",strt);      // only work for 6,7,8 dont know why :(((
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
 int getm(int j){
if(j==0 || j==1)
return 1;
if(j==2 || j==3)
return 2;
if(j==4 || j==5)
return 3;


}


int main()
{
    
    //int i=0;
/*int pid=0,strt=0;
  int shm;
int i,j=0;
pid_t cpid[6];
char semaphrname[5][5];
char semname[5];*/
no = 5;

printf("welcom to main");
for(i=0;i<6;i++)
{
cpid[i]=fork();
printf("%d \n",cpid[i]);
if(cpid[i]==0)
break;
}

sprintf(semaphrname[0],"%d",getpid()+i);

sem1=sem_open(semaphrname[0],O_CREAT,0666,1);
if(sem1==SEM_FAILED)
perror("SEMAPHORE CANNT BE CREATED");
sprintf(semaphrname[1],"%d",getpid()+i);

sem2=sem_open(semaphrname[1],O_CREAT,0666,1);
if(sem2==SEM_FAILED)
perror("SEMAPHORE CANNT BE CREATED");
sprintf(semaphrname[2],"%d",getpid()+i);

sem3=sem_open(semaphrname[2],O_CREAT,0666,1);
if(sem3==SEM_FAILED)
perror("SEMAPHORE CANNT BE CREATED");




if( sem_init(sem1,1,1) < 0)
    {
      perror("semaphore initilization");
      exit(0);
    }
if( sem_init(sem2,1,1) < 0)
    {
      perror("semaphore initilization");
      exit(0);
    }
if( sem_init(sem3,1,1) < 0)
    {
      perror("semaphore initilization");
      exit(0);
    }


if(i==no)
{
int state;
for(i=0;i<no;i++)
waitpid(cpid[i],&state,WUNTRACED);

}
else
for(i=0;i<6;i++)
phillos(i);

//waitpid is a function which waits for the child process to finish executing after that //control switches back to parent
sem_close(sem1);
sprintf(semaphrname[0],"%d",getpid()+i);
sem_unlink(semaphrname[0]);
sem_close(sem2);
sprintf(semaphrname[1],"%d",getpid()+i);
sem_unlink(semaphrname[1]);
sem_close(sem3);
sprintf(semaphrname[2],"%d",getpid()+i);
sem_unlink(semaphrname[2]);
/*for(i=0;i<no;i++)
{
sem_close(sem[i]);
sprintf(semname,"%d",getpid()+i);
sem_unlink(semname);
}
}*/


//}
/*for(i=0;i<6;i++){
if(cpid[k]!=0){
k++;
printf("philosopher %d is called",i);
phillos(k);
}

}*/
/*
    for(i=0; i<6; i++)
    {
        pid=fork();
        if(pid==0)
        {
            //child process
        //  phillos(i);
printf("child process %d \n" ,i);
            _exit(0);
        }
        else
        {
            // parent process only
printf("parent process.... %d \n" ,i);
        }
    }
    strt=1;
*/
while(1);

    return 0;

}


















