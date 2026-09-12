#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("Child PID=%d\n",getpid());
execl("/bin/ls","ls",NULL);
}
else
{
printf("Parent PID=%d\n",getpid());
wait(NULL);
}
return 0;
}  whats the  output
