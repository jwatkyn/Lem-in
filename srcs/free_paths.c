/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_rooms(t_info **info)
{
	t_room	*rooms;
	t_room	*next;

	rooms = (*info)->rooms;
	free((*info)->start);
	free((*info)->end);
	if (!(rooms->next))
	{
		free(rooms->neighbours);
		free(rooms);
		return ;
	}
	while (rooms->next)
	{
		next = rooms->next;
		free(rooms->room);
		free(rooms->neighbours);
		free(rooms);
		rooms = next;
	}
	free(rooms->room);
	free(next->neighbours);
	free(next);
}

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	array = NULL;
}

void	free_links(t_info **info)
{
	t_links	*links;
	t_links	*next;

	links = (*info)->links;
	if (!(links->next))
	{
		free_array(links->link);
		free(links);
		return ;
	}
	while (links->next)
	{
		next = links->next;
		free_array(links->link);
		free(links);
		links = next;
	}
	free_array(next->link);
	free(next);
}

void	free_path(t_path **temp)
{
	t_path	*path;
	t_path	*next;

	path = (*temp);
	if (!(path->next))
	{
		free(path);
		return ;
	}
	while (path->next)
	{
		next = path->next;
		free(path);
		path = next;
	}
	free(path);
}

void	free_paths(t_paths **temp)
{
	t_paths	*paths;
	t_paths	*next;

	paths = *temp;
	if (!(paths->next))
	{
		free_path(&(paths->path));
		free(paths);
		return ;
	}
	next = paths->next;
	ft_putstr(paths->path->door);
	while (paths->next)
	{
		next = paths->next;
		free_path(&(paths->path));
		free(paths);
		paths = next;
	}
	free_path(&(paths->path));
	free(paths);
}
