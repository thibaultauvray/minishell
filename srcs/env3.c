/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:05:39 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/28 17:10:49 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		ft_env_i(int i, char **str, char **envcpyi)
{
	int	j;

	j = 0;
	if (str[i] == NULL)
	{
		while (str[j])
		{
			ft_putendl(str[j]);
			j++;
		}
	}
	if (while_exec(str + i, envcpyi) == 0)
		ft_puterror_env(str, i);
}

t_env		init_var(t_env e)
{
	e.i = 0;
	e.j = 0;
	e.res = 1;
	return (e);
}

void		ft_env_i_opts(char **str)
{
	t_env		e;
	extern char **environ;

	e = init_var(e);
	e.envcpyi = environ;
	while (str[e.i] && ft_strchr(str[e.i], '=') != NULL)
	{
		e.first_s = ft_first(str[e.i], '=');
		while (e.envcpyi[e.j])
		{
			e.first_e = ft_first(e.envcpyi[e.j], '=');
			if (ft_strcmp(e.first_s, e.first_e) == 0)
				e.res = ft_modify_env(&e.envcpyi[e.j], str[e.i]);
			free(e.first_e);
			e.j++;
		}
		if (e.res == 1)
			e.envcpyi = ft_add(e.envcpyi, str[e.i], e.j);
		e.j = 0;
		e.res = 1;
		free(e.first_s);
		e.i++;
	}
	ft_exec_i(str, e.envcpyi, e.i);
}
