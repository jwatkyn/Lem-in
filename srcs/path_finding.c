/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path	*create_path(char *val)
{
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	new->door = val;
	new->ant = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int		no_paths(t_info *info)
{
	t_room	*temp;
	int		i;
	int		j;

	temp = info->rooms;
	while (1)
	{
		if (!ft_strcmp(temp->room, info->start))
			i = temp->no_neighbours;
		if (!ft_strcmp(temp->room, info->end))
			j = temp->no_neighbours;
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	if (i < j)
		return (i);
	else
		return (j);
}

t_paths	*find_paths(t_info **info)
{
	t_paths	*paths;

	paths = (t_paths *)malloc(sizeof(t_paths));
	paths->path = create_path((*info)->start);
	paths->rooms = (*info)->rooms;
	paths = dijkstra(paths, (*info)->end, (*info)->start);
	return (paths);
}
