/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:34:43 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/04/29 13:38:47 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minitalk.h"

int	g_pid = 0;

void	bits_and_bins(int *bits, int *bin)
{
	*bits += 1;
	*bin /= 2;
}

void	handle_sigint(int sig, siginfo_t *si, void *t)
{
	static char	letter;
	static int	bin;
	static int	bits;

	if (g_pid != si->si_pid)
	{
		g_pid = si->si_pid;
		bin = 0;
	}
	if (bits > 7 || bin == 0)
	{
		bits = 0;
		letter = 0;
		bin = 128;
	}
	if (sig == SIGUSR1)
	{
		letter += bin;
		bin /= 2;
		bits++;
	}
	else if (sig == SIGUSR2)
		bits_and_bins(&bits, &bin);
	if (bits > 7)
		write(1, &letter, 1);
}

int	main(void)
{
	int					pid;
	int					clipid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("PID:%d\n", pid);
	act.sa_sigaction = handle_sigint;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
