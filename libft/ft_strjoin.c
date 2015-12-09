/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:28:48 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/27 16:09:59 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		strlen;
	char	*tmp;

	strlen = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	tmp = (char *)malloc(sizeof(*tmp) * (strlen));
	i = 0;
	if (tmp)
	{
		while (*s1)
			tmp[i++] = *s1++;
		while (*s2)
			tmp[i++] = *s2++;
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
