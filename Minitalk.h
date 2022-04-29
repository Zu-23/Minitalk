/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:56:25 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/04/29 13:57:25 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/wait.h>

int		ft_putstr(char *str);
int		ft_putnbr(long a, int i);
int		ft_putchar(char c);
int		ft_hexconv(unsigned long long i, char c);
int		ft_printf(const char *c, ...);
int		ft_print_str(char *str);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);

#endif
