/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:10:15 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/09 18:28:43 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		*recup_oldpwd(char **envcpy)
{
	int		i;
	char	*first;
	char	*str;

	i = 0;
	while (envcpy[i])
	{
		first = ft_first(envcpy[i], '=');
		if (ft_strcmp(first, "OLDPWD") == 0)
			str = ft_last_env(envcpy[i]);
		i++;
	}
	return (str);
}

char		*recup_pwd(char **envcpy)
{
	int		i;
	char	*first;
	char	*str;

	i = 0;
	while (envcpy[i])
	{
		first = ft_first(envcpy[i], '=');
		if (ft_strcmp(first, "PWD") == 0)
			str = ft_last_env(envcpy[i]);
		i++;
	}
	return (str);
}

void		ft_puterrors_cd(char *str, int i)
{
	if (i == 1)
	{
		ft_putstr_fd("cd:cd:13: no such file or directory: ", 2);
		ft_putendl_fd(str, 2);
	}
	if (i == 2)
		ft_putendl_fd("cd : Can't change to home directory", 2);
	if (i == 10)
	{
		ft_putstr_fd("cd:cd:13: string not in pwd: ", 2);
		ft_putendl_fd(str, 2);
	}
	if (i == 42)
	{
		ft_putstr_fd("cd:cd:13: Permission denied : ", 2);
		ft_putendl_fd(str, 2);
	}
}

char		*ft_str_replace(char *pwd, char *s1, char *s2)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*str;

	i = ft_strstr_before(pwd, s1) - ft_strlen(s1);
	tmp = ft_strsub(pwd, 0, i);
	str = ft_strjoin(tmp, s2);
	free(tmp);
	tmp2 = ft_strstr(pwd, s1);
	s1 = ft_strsub(tmp2, ft_strlen(s1), ft_strlen(tmp2) - ft_strlen(s1));
	tmp2 = ft_strjoin(str, s1);
	return (tmp2);
}

char		**ft_cd_two(char **envcpy, char **split)
{
	char	*pwd;
	char	*old_path;

	old_path = recup_pwd(envcpy);
	pwd = recup_pwd(envcpy);
	if (ft_strstr(pwd, split[1]) != NULL)
	{
		pwd = ft_str_replace(pwd, split[1], split[2]);
		if (access(pwd, F_OK) == 0)
		{
			chdir(pwd);
			envcpy = ft_change_path(old_path, envcpy);
		}
	}
	return (envcpy);
}
