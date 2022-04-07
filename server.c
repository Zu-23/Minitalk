#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void handle_sigint(int sig)
{
   
}
  
int main()
{
    int pid;

    pid = getpid();
    printf("PID:%d\n",pid);
    struct sigaction act;
    act.sa_handler = handle_sigint;
    sigaction(SIGUSR1,&act,NULL);
    pause();
}