/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:05:58 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/26 16:57:22 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	if (s && len != 0 && s[start] != '\0' && ft_strlen((char *)s) > start)
	{
		str = NULL;
		i = 0;
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			str[i] = ((char *)s)[start];
			start++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (ft_strdup(""));
}
