/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*delete_current(t_room *rooms, t_room *del)
{
	t_room	*slow_ptr;
	t_room	*fast_ptr;

	fast_ptr = rooms;
	slow_ptr = rooms;
	while (fast_ptr)
	{
		if (!ft_strcmp(fast_ptr->room, del->room))
		{
			if (!ft_strcmp(slow_ptr->room, fast_ptr->room))
				rooms = rooms->next;
			else
				slow_ptr->next = fast_ptr->next;
			free(fast_ptr);
			break ;
		}
		slow_ptr = fast_ptr;
		fast_ptr = fast_ptr->next;
	}
    return (rooms);
}

t_room	*remove_room(t_room *rooms, char *door)
{
	t_room	*temp;

	temp = rooms;
	while (temp->next)
	{
		if (!ft_strcmp(temp->room, door))
		{
			rooms = delete_current(rooms, temp);
			return (rooms) ;
		}
		temp = temp->next;
	}
	if (!ft_strcmp(temp->room, door))
		rooms = delete_current(rooms, temp);
	return (rooms);
}

t_room	*remove_rooms(t_room *rooms, t_path *paths)
{
	t_path *path;

	if (!paths->next)
		return (rooms);
	path = paths->next;
	while (path->next)
	{
		rooms = remove_room(rooms, path->door);
		path = path->next;
	}
	return (rooms);
}
