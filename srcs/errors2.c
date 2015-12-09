/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:07:46 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/09 19:20:08 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				ft_puterror_env(char **str, int i)
{
	ft_putstr("env : \t");
	ft_putstr(str[i]);
	ft_putendl(": No such file or directory");
}

char				*ft_strtrime(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}

t_split				ft_init_variable(t_split s, int i)
{
	if (i == 1)
	{
		s.res = get_next_line(0, &s.line);
		s.line = ft_strtrime(s.line);
		s.pid = fork();
		s.i = 0;
		s.split_t = ft_strsplit(s.line, ' ');
		return (s);
	}
	if (s.i == -1)
		s.i = 0;
	s.b = 1;
	return (s);
}

char				**if_env_empt(char **path_d)
{
	if (path_d[0] == NULL)
		path_d = ft_strsplit("/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin",
				':');
	return (path_d);
}

char				*recup_home(char **envcpy)
{
	int		i;
	char	*first;
	char	*str;

	i = 0;
	str = NULL;
	while (envcpy[i])
	{
		first = ft_first(envcpy[i], '=');
		if (ft_strcmp(first, "HOME") == 0)
		{
			str = ft_last_env(envcpy[i]);
		}
		i++;
	}
	return (str);
}
