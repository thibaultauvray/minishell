/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 17:08:35 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/28 18:03:00 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		**ft_add(char **envcpy, char *str, int j)
{
	envcpy[j] = str;
	envcpy[j + 1] = NULL;
	return (envcpy);
}

void		ft_env_trash2(char **str, int i, char **envcpy)
{
	int	f;

	if (str[i] == NULL)
		ft_putenviron(envcpy);
	else
	{
		if (str[i][0] == '/' || str[i][0] == '.')
			call_execve_prog(str + i, envcpy);
		else
		{
			f = while_exec(str + i, envcpy);
			if (f == 0)
				ft_puterror_env(str, i);
		}
	}
}

void		ft_env_trash(char **envcpy, char **str)
{
	t_env	e;

	e.res = 1;
	e.j = 0;
	e.i = 1;
	while (str[e.i] && ft_strchr(str[e.i], '=') != NULL)
	{
		e.first_s = ft_first(str[e.i], '=');
		while (envcpy[e.j])
		{
			e.first_e = ft_first(envcpy[e.j], '=');
			if (ft_strcmp(e.first_s, e.first_e) == 0)
				e.res = ft_modify_env(&envcpy[e.j], str[e.i]);
			free(e.first_e);
			e.j++;
		}
		if (e.res == 1)
			envcpy = ft_add(envcpy, str[e.i], e.j);
		e.j = 0;
		e.res = 1;
		free(e.first_s);
		e.i++;
	}
	ft_env_trash2(str, e.i, envcpy);
}

void		ft_exec_i(char **str, char **envcpyi, int i)
{
	int	f;

	if (ft_strcmp(str[i], "env") != 0)
	{
		if (str[i][0] == '/' || str[i][0] == '.')
			call_execve_prog(str + i, envcpyi);
		else
		{
			f = while_exec(str + i, envcpyi);
			if (f == 0)
				ft_puterror_env(str, i);
		}
	}
}

void		ft_env(char **str, char **envcpy)
{
	int	i;

	i = 1;
	if (str[1] == NULL)
	{
		ft_putenviron(envcpy);
	}
	if (str[1][0] == '-')
	{
		while (str[i][0] == '-')
		{
			if (ft_is_valid(str[i]) == -1)
				return ;
			i++;
		}
		ft_env_i_opts(str + i);
	}
	else
	{
		ft_env_trash(envcpy, str);
	}
}
