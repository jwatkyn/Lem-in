/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_neighbours(t_room *rooms, t_info *info)
{
	t_room *temp;

	temp = rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->room, info->start))
			if (temp->no_neighbours == 0)
				error();
		if (!ft_strcmp(temp->room, info->end))
			if (temp->no_neighbours == 0)
				error();
		temp = temp->next;
	}
}

char	*ret_neighbour(t_links **links, char *origin)
{
	while ((*links)->next)
	{
		if (!ft_strcmp(origin,(*links)->link[0]))
			return ((*links)->link[1]);
		else if (!ft_strcmp(origin,(*links)->link[1]))
			return ((*links)->link[0]);
		*links = (*links)->next;
	}
	if (!ft_strcmp(origin,(*links)->link[0]))
		return ((*links)->link[1]);
	else if (!ft_strcmp(origin,(*links)->link[1]))
		return ((*links)->link[0]);
	return (NULL);
}

int		get_link_no(t_links *links, char *origin)
{
	int		j;

	j = 0;
	while (links->next)
	{
		if (!ft_strcmp(origin,links->link[0]))
			j++;
		else if (!ft_strcmp(origin,links->link[1]))
			j++;
		links = links->next;
	}
	if (!ft_strcmp(origin,links->link[0]))
		j++;
	else if (!ft_strcmp(origin,links->link[1]))
		j++;
	return (j);	
}

t_room	*get_neighbour(t_room *rooms, t_links *links, t_info *info)
{
	t_room	*temp;
	t_links	*temp2;
	int		number;
	int		i;

	temp = rooms;
	while (1)
	{
		temp2 = links;
		if ((number = get_link_no(links, temp->room)))
		{
			temp->no_neighbours = number;
			temp->neighbours = (char **)malloc(sizeof(char*) * number);
			i = -1;
			while (++i < number)
			{
				temp->neighbours[i]= ret_neighbour(&temp2, temp->room);
				if (!temp2->next)
					break ;
				temp2 = temp2->next;
			}
		}
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	check_neighbours(rooms, info);
	return (rooms);
}