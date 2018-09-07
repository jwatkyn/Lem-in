/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 09:25:56 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 09:25:57 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*current;
	t_dlist	*aux;

	if (alst && *alst)
	{
		current = *alst;
		while (current)
		{
			(*del)(current->content, current->content_size);
			aux = current->next;
			free(current);
			current = aux;
		}
		*alst = NULL;
	}
}
