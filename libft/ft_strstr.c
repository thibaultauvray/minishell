/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:09:08 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/28 16:14:39 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_str	ft_str_b(t_str b, const char *s1, const char *s2)
{
	if (s2[b.j] == s1[b.i])
	{
		b.i++;
		b.res++;
	}
	return (b);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	t_str	b;

	b.res = 0;
	b.i = -1;
	b.j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	if ((int)ft_strlen((char *)s2) > (int)ft_strlen((char *)s1))
		return (NULL);
	while (s1[++b.i] != '\0')
	{
		b.inte = b.i;
		while (s2[b.j] != '\0')
		{
			b = ft_str_b(b, s1, s2);
			if (b.res == (int)ft_strlen(s2))
				return ((char *)s1 + b.i - ft_strlen((char *)s2));
			b.j++;
		}
		b.j = 0;
		b.i = b.inte;
		b.res = 0;
	}
	return (NULL);
}
