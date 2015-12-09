/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:25:12 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/08 17:35:07 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*p;
	unsigned char	*p1;

	p = (unsigned char *)s1;
	p1 = (unsigned char *)s2;
	i = 0;
	while (p[i] == p1[i] && p[i] != '\0')
	{
		i++;
	}
	if (p[i] == p1[i])
	{
		return (0);
	}
	else
	{
		return (p[i] - p1[i]);
	}
}
