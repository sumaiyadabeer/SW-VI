#include<stdio.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
sem_t *sem[10];
int no;
int n =5;
int reader(int val);

int main()
{
int i,j=0;
pid_t cpid[6];
char semaphrname[5][5];
char semname[5];
no = 5;

printf("welcom to main");
for(i=0;i<no;i++)
{
cpid[i]=fork();
if(cpid[i]==0)
break;
}

for(i=0;i<no;i++)
{
sprintf(semaphrname[i],"%d",getpid()+i);
sem[i]=sem_open(semaphrname[i],O_CREAT,0666,1);
if(sem[i]==SEM_FAILED)
perror("SEMAPHORE CANNT BE CREATED");
printf("welcom to sem creation %d\n",no);
}

//kk
if(i==no)
{
int state;
for(i=0;i<no;i++)
waitpid(cpid[i],&state,WUNTRACED);

//waitpid is a function which waits for the child process to finish executing after that //control switches back to parent
for(i=0;i<no;i++)
{
sem_close(sem[i]);
sprintf(semname,"%d",getpid()+i);
sem_unlink(semname);
}
}

else
reader(i);
}

int reader(int val)
{
printf("%d Thinking\n",val+1);
while(1)
{
sem_wait(sem[val%n]);
if(!sem_trywait(sem[(val+1)%n]))
break;
else
sem_post(sem[val%n]);
}
printf("%d Eating\n",val+1);
sleep(2%val);
sem_post(sem[val%n]);
sem_post(sem[(val+1)%n]);
printf("%d Finished Eating\n",val+1);
return 0;
}
