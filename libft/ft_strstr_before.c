/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 14:17:46 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/28 17:33:51 by tauvray          ###   ########.fr       */
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

int				ft_strstr_before(const char *s1, const char *s2)
{
	t_str	b;

	b.res = 0;
	b.i = -1;
	b.j = 0;
	if (ft_strlen(s2) == 0)
		return (0);
	if ((int)ft_strlen((char *)s2) > (int)ft_strlen((char *)s1))
		return (-1);
	while (s1[++b.i] != '\0')
	{
		b.inte = b.i;
		while (s2[b.j] != '\0')
		{
			b = ft_str_b(b, s1, s2);
			if (b.res == (int)ft_strlen(s2))
				return (b.i);
			b.j++;
		}
		b.j = 0;
		b.i = b.inte;
		b.res = 0;
	}
	return (-1);
}
