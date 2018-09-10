/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		visited(t_paths *paths, char *val)
{
	t_room	*temp;

	temp = paths->rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->room, val))
		{
			if (temp->visited == 1)
				return (1);
			else
				return (0);
		}
		if (!temp->next)
			return (0);
		temp = temp->next;
	}
	return (0);
}

t_path	*path_end(t_paths *paths)
{
	t_path	*temp;

	temp = paths->path;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int		no_doors(t_paths *paths, t_path *path)
{
	int		i;
	int		k;
	t_room	*temp;

	k = -1;
	i = 0;
	temp = paths->rooms;
	while (ft_strcmp(path->door, temp->room))
		temp = temp->next;
	while (++k < temp->no_neighbours)
		if(!visited(paths, temp->neighbours[k]))
			i++;
	return (i);
}

t_paths	*not_visited(t_paths *paths, char *door, int val)
{
	t_room	*temp;

	temp = paths->rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->room, door))
		{
			temp->visited = val;
			break;
		}
		temp = temp->next;
	}
	return (paths);
}

t_paths	*remove_visited(t_paths *paths)
{
	t_path	*temp_path;
	t_path	*temp_path1;

	temp_path = paths->path->next;
	while (temp_path->next)
	{
		temp_path1 = temp_path;
		paths = not_visited(paths, temp_path->door, 0);
		temp_path = temp_path->next;
		free(temp_path1);
	}
	paths = not_visited(paths, temp_path->door, 1);
	free(temp_path);
	paths->path->next = NULL;
	return (paths);
}

t_paths	*dijkstra(t_paths *paths, char *end, char *start)
{
	int		i;
	int		k;
	t_room	*temp;
	t_path	*temp3;

	while (ft_strcmp(path_end(paths)->door, end))
	{
		i = no_doors(paths, path_end(paths));
		if (!ft_strcmp(path_end(paths)->door, start) && i == 0)
		{
			paths->path = NULL;
			break ;
		}
		if (i)
		{
			temp = paths->rooms;
			while (ft_strcmp(path_end(paths)->door, temp->room))
				temp = temp->next;
			k = -1;
			while (++k < temp->no_neighbours)
			{
				if (!visited(paths, temp->neighbours[k]))
				{
					temp->visited = 1;
					temp3 = create_path(temp->neighbours[k]);
					temp3->prev = path_end(paths);
					path_end(paths)->next = temp3;
					break ;
				}
				else if (k == temp->no_neighbours)
					paths = remove_visited(paths);
			}	
		}
		else
			paths = remove_visited(paths);
	}
	return (paths);
}