/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:42:38 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/09 18:49:12 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				ft_signal_errors(pid_t pid, int stat, char **str)
{
	if (stat == SIGQUIT)
		ft_putstr_signal(pid, "Quit", str);
	if (stat == SIGHUP)
		ft_putstr_signal(pid, "Hangup", str);
	if (stat == SIGKILL)
		ft_putstr_signal(pid, "Killed", str);
	if (stat == SIGSTOP)
		ft_putstr_signal(pid, "Stopped", str);
	if (stat == SIGTERM)
		ft_putstr_signal(pid, "Terminated", str);
	if (stat == SIGABRT)
		ft_putstr_signal(pid, "Abort", str);
	if (stat == SIGBUS)
		ft_putstr_signal(pid, "Bus error", str);
	if (stat == SIGILL)
		ft_putstr_signal(pid, "illegal hardware instruction", str);
	if (stat == SIGTRAP)
		ft_putstr_signal(pid, "trace trap", str);
	if (stat == SIGEMT)
		ft_putstr_signal(pid, "EMT instruction", str);
	if (stat == SIGFPE)
		ft_putstr_signal(pid, "floating point exception", str);
	if (stat == SIGSEGV)
		ft_putstr_signal(pid, "Segmentation Fault", str);
}

void				ft_putstr_signal(int pid, char *sign, char **str)
{
	int	i;

	i = 0;
	ft_putstr("\033[33;mShashun\033[m: \t");
	ft_putnbr(pid);
	ft_putstr(" ");
	ft_putstr("\033[31;m");
	ft_putstr(sign);
	ft_putstr("\033[m");
	ft_putstr(" | ");
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putendl("");
}
