/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:20:18 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/27 15:24:15 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			ft_num_args(char **split)
{
	int	i;

	i = 1;
	while (split[i])
	{
		i++;
	}
	return (i);
}

char		*ft_modify_setenv(char *envcpy, char *str)
{
	char	*first;

	first = ft_first_env(envcpy, '=');
	envcpy = ft_strjoin(first, str);
	free(first);
	return (envcpy);
}

char		*ft_add_setenv(char *str, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str, "=");
	str = ft_strjoin(tmp, str2);
	free(tmp);
	return (str);
}
