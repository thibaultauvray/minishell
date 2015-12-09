/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:14:16 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/27 16:14:30 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			ft_nu(char **envcpy)
{
	int	i;

	i = 1;
	while (envcpy[i])
	{
		i++;
	}
	return (i);
}

char		**ft_del(char **envcpy, int i)
{
	int		j;

	j = 0;
	while (envcpy[j])
	{
		if (j >= i)
		{
			envcpy[j] = envcpy[j + 1];
		}
		j++;
	}
	return (envcpy);
}

char		**ft_unsetenv(char **split, char **envcpy)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (split[j])
	{
		while (envcpy[i])
		{
			if (ft_strcmp(split[j], ft_first(envcpy[i], '=')) == 0)
			{
				envcpy = ft_del(envcpy, i);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (envcpy);
}
