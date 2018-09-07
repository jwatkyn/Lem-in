/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_paths	*add_end_paths(t_paths *paths, t_paths *next)
{
	t_paths	*temp;

	temp = paths;
	if (!paths)
	{
		paths = next;
		return (paths);
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = next;
	}
	return (paths);
}

int		main(void)
{
	t_info	*info;
	t_room	*rooms;
	t_links	*links;
	t_paths *paths;
	t_paths *paths_temp;
	int		j;

	info = (t_info *)malloc(sizeof(t_info));
	info->ants = 0;
	info->cur_ant = 0;
	info->link_number = 0;
	rooms = NULL;
	links = NULL;
	info = parsing(info, &rooms, &links);
	rooms = get_neighbour(rooms, links);
	info->rooms = rooms;
	info->links = links;
	info->paths = 0;
	j = no_paths(info);
	paths = NULL;
	while(j)
	{
		paths_temp = find_paths(&info);
		paths = add_end_paths(paths, paths_temp);
		info->paths++;
		j--;
	}
	send_ants(info, paths);
	free_rooms(&info);
	free_links(&info);
	free_paths(&paths);
	free(info);
	exit (0);
}
