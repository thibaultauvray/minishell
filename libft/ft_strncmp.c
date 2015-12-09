/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:26:59 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/08 17:34:11 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*p1;
	int				cmp;

	p = (unsigned char *)s1;
	p1 = (unsigned char *)s2;
	cmp = 0;
	i = 0;
	while ((p[i] != '\0' || p1[i] != '\0') && i < n && cmp == 0)
	{
		cmp = p[i] - p1[i];
		i++;
	}
	return (cmp);
}
