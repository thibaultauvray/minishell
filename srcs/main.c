/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 14:29:37 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/09 19:21:58 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				ft_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	signal(SIGTSTP, SIG_IGN);
}

char				**ft_check_env_init(char **split, char **envcpy)
{
	if (split[0] != NULL && ft_strcmp(split[0], "setenv") == 0)
		envcpy = ft_setenv(split, envcpy);
	if (split[0] != NULL && ft_strcmp(split[0], "unsetenv") == 0)
		envcpy = ft_unsetenv(split, envcpy);
	else if (split[0] != NULL && ft_strcmp(split[0], "cd") == 0)
		envcpy = ft_cd(split, envcpy);
	return (envcpy);
}

int					ft_init_exe(char *line, char **split, char **envcpy)
{
	if (ft_strcmp(split[0], "setenv") != 0 &&
			ft_strcmp(split[0], "unsetenv") != 0)
	{
		ft_proc(line, envcpy);
	}
	test_error(split);
	return (1);
}

int					ft_init_shell(char **envcpy)
{
	t_split		s;

	s.b = 0;
	while (s.b == 0)
	{
		s = ft_init_variable(s, 1);
		envcpy = ft_check_env_init(s.split_t, envcpy);
		s.i = ft_exit(s.line);
		if (s.res == 1 && ft_exit(s.line) == -1)
		{
			if (s.pid == 0)
				return (ft_init_exe(s.line, s.split_t, envcpy));
			else
				wait(&s.stats_loc);
			ft_prompt();
		}
		else if (s.res == 1 && s.i != -1)
			s = ft_init_variable(s, 2);
		else
			s.b = 1;
		free_tab(s.split_t);
		free(s.line);
	}
	return (s.i);
}

int					main(void)
{
	extern char	**environ;
	char		**envcpy;
	int			i;

	envcpy = ft_strdupd(environ);
	ft_signal();
	ft_prompt();
	i = ft_init_shell(envcpy);
	return (i);
}
