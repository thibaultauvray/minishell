/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 19:17:46 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/10 14:11:37 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int					ft_exit(char *line)
{
	char	**str;
	int		i;
	int		boul;

	boul = 1;
	str = ft_strsplit(line, ' ');
	i = 0;
	if (str[0] && ft_strcmp("exit", str[0]) == 0 && ft_num_args(str) < 3)
	{
		if (str[1] && !str[2])
		{
			while (str[1][i])
			{
				if (ft_isdigit(str[1][i] == 0))
					boul = 0;
				i++;
			}
			if (boul == 1)
				return (ft_atoi(str[1]));
			else
				return (0);
		}
		return (1);
	}
	return (-1);
}

t_error				init_pwd(t_error e, char **envcpy)
{
	e.path = recup_oldpwd(envcpy);
	e.pwd = recup_pwd(envcpy);
	return (e);
}
