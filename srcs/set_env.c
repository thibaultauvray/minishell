/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 12:44:46 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/27 15:24:12 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		*ft_modify_setenv_emp(char *str)
{
	return (ft_first_env(str, '='));
}

char		**ft_setenv_ac(char **split, char **envcpy)
{
	int	cpt;
	int	k;

	k = 0;
	cpt = 0;
	while (envcpy[cpt])
	{
		if (ft_strcmp(split[1], ft_first(envcpy[cpt], '=')) == 0)
		{
			if (split[2])
				envcpy[cpt] = ft_modify_setenv(envcpy[cpt], split[2]);
			else
				envcpy[cpt] = ft_modify_setenv_emp(envcpy[cpt]);
			k++;
		}
		cpt++;
	}
	if (k == 0)
	{
		if (split[2])
			envcpy[cpt] = ft_add_setenv(split[1], split[2]);
		else
			envcpy[cpt] = ft_add_setenv(split[1], "");
	}
	return (envcpy);
}

int			ft_if_eg(char *str)
{
	if (ft_strchr(str, '=') == NULL)
		return (0);
	return (-1);
}

char		**ft_setenv(char **split, char **envcpy)
{
	int	i;

	i = ft_num_args(split);
	if (split[1] != NULL && ft_if_eg(split[1]) == 0)
	{
		if (i == 3 || i == 2)
			envcpy = ft_setenv_ac(split, envcpy);
	}
	return (envcpy);
}
