/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:34:37 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/04/29 16:44:09 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	checkpid(char *pid, int arg)
{
	int	i;

	i = -1;
	if (arg != 3)
	{
		ft_printf("wrong amount of arguments or wrong PID");
		return (1);
	}
	while (pid[++i])
	{
		if (ft_isalpha(pid[i]) == 1)
		{
			ft_printf("wrong PID!");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	int			pid;
	static int	bit;
	char		*msg;

	if (checkpid(argv[1], argc) == 1)
		return (1);
	i = 0;
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (msg[i])
	{
		while (bit < 8)
		{
			if (msg[i] & 128 >> bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(700);
		}
		bit = 0;
		i++;
	}
}
