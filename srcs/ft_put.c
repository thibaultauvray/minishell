/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:11:33 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/10 14:05:49 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				ft_prompt(void)
{
	ft_putstr("\033[5;31;m");
	ft_putstr(":-> ");
	ft_putstr("\033[m");
}

void				ft_putenviron(char **envcpy)
{
	int	i;

	i = 0;
	while (envcpy[i])
	{
		ft_putstr(envcpy[i]);
		ft_putn();
		i++;
	}
}

int					call_execve(char *cmd, char **split, char **envcpy)
{
	int stat_loc;
	int	pid_t;

	pid_t = fork();
	if (pid_t == 0)
	{
		execve(cmd, split, envcpy);
		exit(1);
	}
	else
	{
		waitpid(pid_t, &stat_loc, 0);
		if (WIFSIGNALED(stat_loc))
		{
			ft_signal_errors(pid_t, stat_loc, split);
		}
	}
	return (stat_loc);
}

void				call_execve_prog(char **str, char **envcpy)
{
	int	stat_loc;
	int	pid_t;

	pid_t = fork();
	if (pid_t == 0)
	{
		execve(str[0], str, envcpy);
		exit(1);
	}
	else
	{
		wait(&stat_loc);
		if (WIFSIGNALED(stat_loc))
		{
			ft_signal_errors(pid_t, stat_loc, str);
		}
	}
}

void				ft_proc(char *line, char **envcpy)
{
	char	**split;

	line = ft_strtrim(line);
	split = ft_strsplit(line, ' ');
	ft_trim_split(split);
	if (ft_strcmp(split[0], "cd") != 0)
	{
		if (split[0][0] == '/' || split[0][0] == '.')
		{
			call_execve_prog(split, envcpy);
			ft_puterror_slash(split);
		}
		else if (ft_strcmp(split[0], "env") == 0)
			ft_env(split, envcpy);
		else if (ft_strcmp(split[0], "setenv") != 0)
		{
			while_exec(split, envcpy);
			ft_puterror_cmd(split, envcpy);
		}
	}
	else
		ft_errors_cd(split, envcpy);
	free_tab(split);
}
