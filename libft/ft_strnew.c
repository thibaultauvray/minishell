/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:58:17 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/08 16:06:46 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if (!(mem = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
