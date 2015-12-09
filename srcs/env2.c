/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:30:40 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/27 15:39:09 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		*ft_first(char *str, int c)
{
	unsigned int		i;

	i = 0;
	while (str[i] != c)
		i++;
	return (ft_strsub(str, 0, i));
}

char		*ft_first_env(char *str, int c)
{
	unsigned int		i;

	i = 0;
	while (str[i] != c)
		i++;
	return (ft_strsub(str, 0, i + 1));
}

char		*ft_last(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '=')
	{
		i++;
	}
	return (ft_strsub(str, i, ft_strlen(str) - i));
}

int			ft_modify_env(char **envcpy, char *str)
{
	char	*first;
	char	*last;

	first = ft_first(*envcpy, '=');
	last = ft_last(str);
	*envcpy = ft_strjoin(first, last);
	free(first);
	free(last);
	return (0);
}

int			ft_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'i' && str[i] != '-')
		{
			ft_puterror_arg(str[i], "env");
			return (-1);
		}
		i++;
	}
	return (0);
}
