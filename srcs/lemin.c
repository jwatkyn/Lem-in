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
	t_paths *temp_paths;
	t_paths *paths;
	int		j;

	info = (t_info *)malloc(sizeof(t_info));
	info->ants = 0;
	info->cur_ant = 0;
	info->link_number = 0;
	rooms = NULL;
	links = NULL;
	info = parsing(info, &rooms, &links);
	if (!rooms || !links || info->stt != 2 || info->ed != 2)
		error();
	rooms = get_neighbour(rooms, links, info);
	info->rooms = rooms;
	info->links = links;
	info->paths = 0;
	j = no_paths(info);
	paths = NULL;
	while(j)
	{
		temp_paths = find_paths(&info);
		if (!temp_paths->path)
			break ;
		paths = add_end_paths(paths, temp_paths);
		info->paths++;
		j--;
	}
	if (!paths || paths->path == NULL)
		error();
	send_ants(info, paths);
	free_rooms(&info);
	free_links(&info);
	free_paths(&paths);
	free(info);
	exit (0);
}
