/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 09:28:07 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 09:28:09 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddh(t_dlist **alst, t_dlist *new, t_dlist *tail)
{
	t_dlist	*crt;

	if (alst && new)
	{
		new->next = *alst;
		new->previous = NULL;
	}
	crt = new;
	while (crt)
	{
		crt->head = new;
		crt->tail = tail;
		crt = crt->next;
	}
}

void	ft_dlstaddt(t_dlist **alst, t_dlist *new, t_dlist *head)
{
	t_dlist	*crt;

	if (alst && new)
	{
		new->next = NULL;
		new->previous = *alst;
		new->head = head;
		new->tail = new;
	}
	crt = head;
	while (crt)
	{
		crt->head = head;
		crt->tail = new;
		crt = crt->next;
	}
}
