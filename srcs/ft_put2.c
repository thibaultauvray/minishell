/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:14:10 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/09 19:20:08 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int					ft_dif_split(char **split)
{
	int	i;
	int	r;

	r = 0;
	i = 0;
	while (split[i])
	{
		while (split[i][r])
		{
			if (split[i][r] != '\t')
				return (i);
			r++;
		}
		r = 0;
		i++;
	}
	return (0);
}

int					while_exec(char **split, char **envcpy)
{
	t_exe	e;

	e.r = ft_dif_split(split);
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
		e.path = ft_strjoin(e.tmp, split[e.r]);
		free(e.tmp);
		e.err = call_execve(e.path, split, envcpy);
		if (e.err != 256)
			e.res = 1;
		ft_strdel(&e.path);
		free(e.path_d[e.i]);
		e.i++;
	}
	free(e.path);
	return (e.res);
}

void				handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		if (wait(NULL) == -1)
		{
			ft_putn();
			ft_prompt();
		}
	}
}

char				**ft_strdupd(char **environ)
{
	int		i;
	char	**envcpy;

	i = 0;
	while (environ[i])
	{
		i++;
	}
	if (!(envcpy = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (environ[i])
	{
		envcpy[i] = ft_strdup(environ[i]);
		i++;
	}
	envcpy[i] = NULL;
	return (envcpy);
}

char				**ft_trim_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_strtrim(str[i]);
		i++;
	}
	return (str);
}
