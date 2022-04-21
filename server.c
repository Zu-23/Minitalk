#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include"LIBFT_42/libft.h"
int strl(char *str)
{
	int len;

	len = 0;
	if (!str)
		return(0);
	while (str[len])
		len++;

	return(len);
}
char *msgconc(char **msg,char letter)
{
	int 	len;
	char	*tmp;
	int		i;

	if (!letter)
		return (NULL);
	len = strl((*msg));
	tmp = (char *)malloc(len + 2);
	i = -1;
	if ((*msg))
	{
		while ((*msg)[++i])
			tmp[i] = (*msg)[i];
	free((*msg));
	}
	if (i == -1)
		tmp[++i] = letter;
	else
		tmp[i] = letter;
	tmp[++i] = '\0';
	*msg = tmp;
}

void handle_sigint(int sig)
{
   static char	letter;
   char 		*msg;
   static int	bin;
   static int	bits;
   static int	null;

	msg = NULL;
	if (bits > 7 || bin == 0)
	{
		bits = 0;
		letter = 0;
		bin = 128;
		null = 0;
	}
	if (sig == SIGUSR1)
	{
		letter += bin;
		bin /= 2;
		bits++;
	}
	else if (sig == SIGUSR2)
	{
		bin /= 2;
		bits++;
		//printf("null:%d bits:%d\n",null,bits);
		null++;
	}
	if( bits > 7)
	{
		//printf("%d\n",null);
		msgconc(&msg, letter);
		printf("null: %d\n and msg: %s\n",null,msg);
		if (null > 7)
		{
			printf("whats my value %d\n",null);
			printf("%s\n",msg);
			//free(msg);
			//msg = NULL;
		}
	}
	
}
  
int main()
{
	int pid;

	pid = getpid();
	printf("PID:%d\n",pid);
	// struct sigaction act;
	// act.sa_sigaction = handle_sigint;
	// sigaction(SIGUSR1,&act,NULL);
	// sigaction(SIGUSR2,&act,NULL);
	signal(SIGUSR1, handle_sigint);
	signal(SIGUSR2, handle_sigint);
	while(1)
	pause();
}