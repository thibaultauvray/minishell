/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:34:46 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/08 16:05:22 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = NULL;
	if (size == 0)
		return (NULL);
	if (size)
	{
		mem = (void *)malloc(sizeof(char) * size);
		if (mem)
			ft_bzero(mem, size);
	}
	return (mem);
}
