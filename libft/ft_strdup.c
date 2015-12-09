/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/07 16:11:55 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/08 17:33:34 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(*src) * ft_strlen(src) + 1)))
		return (0);
	return (ft_strcpy(str, src));
}
