/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*create(char *val, int x, int y)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->room = ft_strdup(val);
	new->visited = 0;
	new->x = x;
	new->y = y;
	new->neighbours = NULL;
	new->no_neighbours = 0;
	new->next = NULL;
	return (new);
}

t_room		*add_end(t_room *head, char *val, int x, int y)
{
	t_room	*new;
	t_room	*temp;

	new = create(val, x, y);
	temp = head;
	if (head == NULL)
		head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (head);
}

t_room		*add_begin(t_room *head, char *val, int x, int y)
{
	t_room *new;

	new = create(val, x, y);
	new->next = head;
	return (new);
}

t_room		*del_end(t_room *head)
{
	t_room *temp1;
	t_room *temp2;

	if (!head)
		return (NULL);
	temp1 = head;
	temp2 = NULL;
	while(temp1->next != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}
	if (temp2)
		temp2->next = NULL;
	if (temp1 == head)
		head = NULL;
	free(temp1);
	return (head);
}

t_room		*del_begin(t_room *head)
{
	t_room *temp;

	if (!head)
		return (NULL);
	if (!(head->next))
	{
		free(head);
		return (NULL);
	}
	temp = head;
	head = head->next;
	temp->next = NULL;
	free(temp);
	return (head);
}