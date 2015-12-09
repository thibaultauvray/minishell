/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:11:12 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/10 14:39:12 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_error		ft_initiz(t_error e, char **split)
{
	e.tmp = ft_strjoin(e.path, "/");
	e.path = ft_strjoin(e.tmp, split[1]);
	free(e.tmp);
	return (e);
}

int			ft_change_dire(char **envcpy)
{
	char	*str;

	str = recup_home(envcpy);
	if (chdir(str) == -1)
		return (0);
	return (1);
}

void		ft_errors_cd2(char **split, char **envcpy)
{
	if (ft_num_args(split) == 1 && ft_strcmp(split[0], "cd") == 0)
	{
		if (recup_home(envcpy) == NULL)
			ft_putendl_fd("cd : No home directory", 2);
		else if (ft_change_dire(envcpy) == 0)
			ft_putendl_fd("cd : Can't change to home directory", 2);
	}
}

void		ft_errors_cd(char **split, char **envcpy)
{
	t_error		e;
	struct stat	*stats;

	e = init_pwd(e, envcpy);
	if (ft_num_args(split) != 1 && split[1][0] == '~')
		split[1] = ft_change_path_ti(split[1]);
	if (ft_num_args(split) == 3 && ft_strstr(e.path, split[1]) == NULL)
		ft_puterrors_cd(split[1], 10);
	if (ft_num_args(split) == 3)
		e.path = ft_str_replace(e.pwd, split[1], split[2]);
	if (ft_num_args(split) == 2 && split[1][0] != '/')
		e = ft_initiz(e, split);
	if (ft_num_args(split) == 2 && split[1][0] == '/')
		e.path = split[1];
	ft_errors_cd2(split, envcpy);
	if (!(stats = (struct stat *)malloc(sizeof(struct stat))))
		return ;
	e.i = stat(e.path, stats);
	if (e.i < 0 && ft_num_args(split) == 2)
		ft_puterrors_cd(split[1], 1);
	else if ((e.dp = opendir(e.path)) == NULL && ft_num_args(split) == 2)
		ft_puterrors_cd(split[1], 42);
	else if ((e.dp = opendir(e.path)) == NULL && ft_num_args(split) == 3)
		ft_puterrors_cd(e.path, 42);
	free(stats);
}

void		free_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
