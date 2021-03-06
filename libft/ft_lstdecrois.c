/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdecrois.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:28:39 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/08 17:43:24 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdecrois(t_list *liste)
{
	t_list	*tmp;
	int		i;
	t_list	*head;

	head = liste;
	i = count_list(liste);
	while (i)
	{
		liste = head;
		while (liste != NULL)
		{
			if (liste->next && ft_strcmp(liste->content, liste->next->content)
					< 0)
			{
				tmp = liste->content;
				liste->content = liste->next->content;
				liste->next->content = tmp;
			}
			liste = liste->next;
		}
		i--;
	}
	liste = head;
	return (liste);
}
