/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:55:10 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/09 18:45:18 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char		*ft_change_path_ti(char *split)
{
	char	*tmp;
	int		i;

	i = 0;
	while (split[i])
	{
		i++;
	}
	if (i == 1)
		tmp = ft_strdup("");
	else
		tmp = ft_strsub(split, 1, i);
	split = ft_strjoin("/nfs/zfs-student-2/users/2014/tauvray", tmp);
	free(tmp);
	return (split);
}

char		**ft_cd(char **split, char **envcpy)
{
	char	*old_path;
	char	buf[PATH_MAX + 1];
	char	*str;

	if (ft_num_args(split) != 1 && split[1][0] == '~')
		split[1] = ft_change_path_ti(split[1]);
	old_path = getcwd(buf, PATH_MAX + 1);
	if (ft_num_args(split) == 1)
	{
		str = recup_home(envcpy);
		if (str)
		{
			chdir(str);
			envcpy = ft_change_path(old_path, envcpy);
			return (envcpy);
		}
	}
	if (ft_num_args(split) == 3)
		envcpy = ft_cd_two(envcpy, split);
	if (access(split[1], F_OK) == 0)
	{
		chdir(split[1]);
		envcpy = ft_change_path(old_path, envcpy);
	}
	return (envcpy);
}

char		*ft_modify_unsetenv(char *envcpy, char *str)
{
	char	*first;

	first = ft_first_env(envcpy, '=');
	envcpy = ft_strjoin(first, str);
	free(first);
	return (envcpy);
}

char		**ft_change_path(char *old, char **envcpy)
{
	int		i;
	char	buf[PATH_MAX + 1];
	char	*ac_path;

	ac_path = getcwd(buf, PATH_MAX + 1);
	if (ft_strstr(ac_path, "/Volumes/Data") != NULL)
		ac_path = ft_strsub(ac_path, 13, ft_strlen(ac_path));
	if (ft_strstr(old, "/Volumes/Data") != NULL)
		old = ft_strsub(old, 13, ft_strlen(old));
	i = 0;
	while (envcpy[i])
	{
		if (ft_strcmp(ft_first(envcpy[i], '='), "PWD") == 0)
			envcpy[i] = ft_modify_unsetenv(envcpy[i], ac_path);
		else if (ft_strcmp(ft_first(envcpy[i], '='), "OLDPWD") == 0)
			envcpy[i] = ft_modify_unsetenv(envcpy[i], old);
		i++;
	}
	return (envcpy);
}

char		*ft_last_env(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '=')
	{
		i++;
	}
	return (ft_strsub(str, i + 1, ft_strlen(str) - i));
}
