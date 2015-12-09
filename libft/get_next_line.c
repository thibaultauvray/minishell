/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:01:13 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/27 16:10:36 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	ft_find_n(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_frontend(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(buf))))
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
	}
	i++;
	while (buf[i] != '\0')
	{
		str[j] = buf[i];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_backend(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(buf))))
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_tmp(int i, char *s1, char **line)
{
	if (i == 0)
	{
		*line = ft_backend(s1);
		s1 = ft_frontend(s1);
	}
	else
	{
		*line = ft_backend(s1);
		s1 = NULL;
	}
	return (s1);
}

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*tmp = NULL;

	if (!tmp || line == NULL)
		if (!(tmp = (char *)malloc(sizeof(char))) || line == NULL)
			return (-1);
	while ((((ret = read(fd, buf, BUFF_SIZE))) > 0) || tmp[0] != '\0')
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (ft_find_n(tmp) == 1)
		{
			tmp = ft_tmp(0, tmp, line);
			return (1);
		}
		else if (ft_strlen(buf) == 0)
		{
			tmp = ft_tmp(42, tmp, line);
			return (0);
		}
	}
	*line = ft_strdup("");
	return (0);
}
