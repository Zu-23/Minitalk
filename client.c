#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include "LIBFT_42/libft.h"

	
int	main(int argc, char **argv)
{
   int		i;
   int      pid;
   int		bit;
   char 	*msg;
	
	pid = ft_atoi(arv[1]);
  	bit = 0;
	i = 0;
	msg = argv[1];
  
   if (argc != 2)
   	return (1);
	
  	while(msg[i])
	{
		while (bit < 8)
		{
			if (msg[i] & 128 >> bit)
				kill(pid, SIGUSR1);
			else
				kill(pid,SIGUSR2);
			bit++;
		}
		bit = 0;
		i++;
	}
}
