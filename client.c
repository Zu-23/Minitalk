#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include "LIBFT_42/libft.h"
int	checkpid(char *pid, int arg)
{
	int i;

	i = -1;
	if (arg != 3)
	{
		printf("wrong number of arguments\n");
		return (1);
	}
	while (pid[++i])
	{
		if (ft_isalpha(pid[i]) == 1)
			{
				printf("wrong pid!\n");
				return (1);
			}
	}
	return (0);
}
	
int	main(int argc, char **argv)
{
   int		i;
   int      pid;
   int		bit;
   char 	*msg;
	
	if (checkpid(argv[1],argc) == 1)
		return (0);
	pid = atoi(argv[1]);
  	bit = 0;
	i = 0;
	msg = argv[2];
  	while(msg[i])
	{
		while (bit < 8)
		{
			if (msg[i] & 128 >> bit)
				kill(pid, SIGUSR1);
			else
				kill(pid,SIGUSR2);

			usleep(100);
			bit++;
		}
		bit = 0;
		i++;
	}
	// while (bit < 8)
	// {
	// 	//printf("%d	",bit);
	// 	kill(pid,SIGUSR2);
	// 	bit++;
	// 	usleep(40);
	// }
}
