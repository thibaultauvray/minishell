/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:30:30 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/09 18:44:09 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_puterror_arg(char str, char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(str, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("usage:env [-i] [name=value ...][utility [argument ...]]", 2);
}

void	ft_puterror_slash(char **split)
{
	if (open(split[0], O_RDONLY) < 0)
	{
		ft_putstr_fd("sh1 : no shuch file or directory: ", 2);
		ft_putendl_fd(split[0], 2);
	}
}

int		ft_puterror_check(char **split, char **envcpy)
{
	t_errors	e;

	if (split[0] && ft_strcmp (split[0], "exit") == 0)
		return (1);
	e.path = ft_strsub(envcpy[0], 5, ft_strlen(envcpy[0]));
	e.path_d = ft_strsplit(e.path, ':');
	e.path_d = if_env_empt(e.path_d);
	if (e.path_d[0] != NULL)
		free(e.path);
	e.res = 0;
	e.i = 0;
	while (e.path_d[e.i] != NULL)
	{
		e.tmp = ft_strjoin(e.path_d[e.i], "/");
		e.path = ft_strjoin(e.tmp, split[0]);
		if (ft_strchr(split[0], '\t') != NULL)
			e.res = 1;
		free(e.tmp);
		if (open(e.path, O_RDONLY) > 0)
			e.res = 1;
		ft_strdel(&e.path);
		free(e.path_d[e.i]);
		e.i++;
	}
	return (e.res);
}

void	ft_puterror_cmd(char **split, char **envcpy)
{
	if (ft_puterror_check(split, envcpy) == 0)
	{
		ft_putstr_fd("Command not found : ", 2);
		ft_putendl_fd(split[0], 2);
	}
}

void	test_error(char **split)
{
	if (split[0] != NULL)
	{
		if (ft_strcmp(split[0], "unsetenv") == 0 && ft_num_args(split) <= 1)
			ft_putendl_fd("unsetenv: Too few arguments", 2);
		if (ft_strcmp(split[0], "setenv") == 0 && ft_num_args(split) <= 1)
			ft_putendl_fd("unsetenv: Too few arguments", 2);
		if (ft_strcmp(split[0], "setenv") == 0)
		{
			if (ft_num_args(split) >= 4)
				ft_putendl_fd("setenv: Too many arguments.", 2);
			else if (ft_if_eg(split[1]) == -1)
				ft_putendl_fd("setenv: Syntax Error.", 2);
		}
		if (ft_strcmp(split[0], "exit") == 0 && ft_num_args(split) >= 3)
			ft_putendl_fd("exit: Too many arguments", 2);
	}
}
