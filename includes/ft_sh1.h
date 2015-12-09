/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 14:30:16 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/10 14:11:13 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include <sys/stat.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>
# include <dirent.h>

typedef struct		s_env
{
	int				i;
	int				res;
	int				j;
	char			*first_s;
	char			*first_e;
	char			**envcpyi;
}					t_env;

typedef struct		s_exe
{
	char			**path_d;
	char			*path;
	char			*tmp;
	int				i;
	int				err;
	int				r;
	int				res;
}					t_exe;

typedef struct		s_split
{
	char			*line;
	pid_t			pid;
	int				b;
	int				res;
	int				stats_loc;
	char			**split_t;
	int				i;
}					t_split;

typedef struct		s_error
{
	int				i;
	char			*path;
	char			*tmp;
	DIR				*dp;
	char			*pwd;
}					t_error;

typedef struct		s_errors
{
	char			**path_d;
	char			*path;
	char			*tmp;
	int				i;
	int				res;
}					t_errors;

int					get_next_line(int const fd, char **line);
void				ft_signal_errors(pid_t pid, int stat, char **str);
void				ft_putstr_signal(int pid, char *sign, char **str);
void				ft_putenviron(char **envcpy);
void				ft_prompt();
int					while_exec(char **split, char **envcpy);
void				ft_puterror_env(char **str, int i);
void				ft_env(char **str, char **envcpy);
void				ft_puterror_arg(char str, char *cmd);
char				**ft_setenv(char **split, char **envcpy);
void				call_execve_prog(char **str, char **envcpy);
int					ft_modify_env(char **envcpy, char *str);
char				*ft_first(char *str, int c);
char				*ft_last(char *str);
char				*ft_first_env(char *str, int c);
int					ft_if_eg(char *str);
int					ft_num_args(char **split);
char				**ft_unsetenv(char **split, char **envcpy);
char				**ft_cd(char **split, char **envcpy);
void				ft_errors_cd(char **split, char **envcpy);
void				ft_puterror_cmd(char **split, char **envcpy);
void				ft_puterror_slash(char **split);
void				test_error(char **split);
int					ft_is_valid(char *str);
void				ft_env_i(int i, char **str, char **envcpyi);
void				ft_proc(char *line, char **envcpy);
void				handle_signal(int signo);
char				**ft_strdupd(char **environ);
char				*ft_change_path_ti(char *split);
char				*ft_modify_unsetenv(char *envcpy, char *str);
char				*ft_last_env(char *str);
char				**ft_change_path(char *old, char **envcpy);
char				*ft_modify_setenv(char *envcpy, char *str);
char				*ft_add_setenv(char *str, char *str2);
int					call_execve(char *cmd, char **split, char **envcpy);
void				free_tab(char **split);
void				ft_env_i_opts(char **str);
char				**ft_add(char **envcpy, char *str, int j);
char				**ft_cd_two(char **envcpy, char **split);
void				ft_puterrors_cd(char *str, int i);
char				*recup_pwd(char **envcpy);
char				*recup_oldpwd(char **envcpy);
void				ft_exec_i(char **str, char **envcpyi, int i);
char				**ft_trim_split(char **str);
char				*ft_str_replace(char *pwd, char *s1, char *s2);
t_split				ft_init_variable(t_split s, int i);
char				*recup_home(char **envcpy);
char				**if_env_empt(char **path_d);
char				*recup_home(char **envcpy);
int					ft_exit(char *line);
t_error				init_pwd(t_error e, char **envcpy);
#endif
