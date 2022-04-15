#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void handle_sigint(int sig)
{
   static int	letter;
   static int	bin;
   static int	bits;
   static int	null;

	if (bits > 7 || bin == 0)
	{
		printf("did i enter?");
		if(letter != 0)
			//printf("result is %c \n",letter);
		bits = 0;
		letter = 0;
		bin = 128;
	}
	if (sig == SIGUSR1)
	{
		//printf("i got sig\n");
		letter += bin;
		bin /= 2;
		bits++;
		printf("value of letter:%d, bin:%d bits:%d\n",letter,bin,bits);
	}
	else if (sig == SIGUSR2)
	{
		bin /= 2;
		bits++;
		null++;
		printf("value of letter:%d, bin:%d bits:%d\n",letter,bin,bits);

	}
	if (null == 8 || bits > 7)
	{
		printf("%c\n",letter);
		//return ;
	}
	
}
  
int main()
{
	int pid;

	pid = getpid();
	printf("PID:%d\n",pid);
	struct sigaction act;
	act.sa_handler = handle_sigint;
	sigaction(SIGUSR1,&act,NULL);
	sigaction(SIGUSR2,&act,NULL);
	while(1)
	pause();
}