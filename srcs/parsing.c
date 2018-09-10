/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	get_ants(char *line)
{
	int i;

	i = -1;
	if (!line || !line[0])
		error();
	while (line[++i])
		if (!ft_isdigit(line[i]))
			error();
	return (ft_atoi(line));
}

void	check_room2(char **str, t_room *rooms, int x, int y)
{
	t_room	*temp;

	temp = rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->room, str[0]) ||
		 (temp->x == x && temp->y == y))
			error();
		temp = temp->next;
	}
}

void	check_pipe(char **str, t_room *rooms)
{
	t_room	*temp;

	temp = rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->room, str[0]) ||
		 !ft_strcmp(temp->room, str[1]))
			error();
		temp = temp->next;
	}
}

void	check_room(char **str, t_room *rooms)
{
	int i;
	int k;

	i = 0;
	while (str[i])
		i++;
	if (str[0][0] == 'L' || i != 3)
		error();
	k = -1;
	while (str[1][++k])
		if (!ft_isdigit(str[1][k]))
			error();
	k = -1;
	while (str[2][++k])
		if (!ft_isdigit(str[2][k]))
			error();
	if (str[1][0] == '\0' || str[2][0] == '\0')
		error();
	check_room2(str, rooms, ft_atoi(str[1]), ft_atoi(str[2]));
}

t_info	*parsing(t_info *info, t_room **rooms, t_links **links)
{
	char	*line;
	char	**str;

	while (get_next_line(0, &line))
	{
		if (!line || !line[0])
			error();
		if (!(info->ants) && line[0] != '#')
		{
			info->ants = get_ants(line);
			ft_strdel(&line);
			continue ;
		}
		if (info->stt == 1 && line[0] != '#')
		{
			info->stt = 2;
			str = ft_strsplit(line, ' ');
			check_room(str, *rooms);
			info->start = ft_strdup(str[0]);
			free_array(str);
		}
		if (info->ed == 1 && line[0] != '#')
		{
			info->ed = 2;
			str = ft_strsplit(line, ' ');
			check_room(str, *rooms);
			info->end = ft_strdup(str[0]);
			free_array(str);
		}
		if (line && line[0] == '#')
		{
			if (!ft_strcmp(line, "##start"))
			{
				info->stt == 2 ? error() : 0;
				info->stt = 1;
			}
			else if (!ft_strcmp(line, "##end"))
			{
				info->ed == 2 ? error() : 0;
				info->ed = 1;
			}
			ft_strdel(&line);
			continue ;
		}
		if (ft_strchr(line, '-') && ft_strncmp(line, "#", 1))
		{
			info->link_number++;	
			*links = add_link(*links, line, *rooms);
		}
		else
		{
			str = ft_strsplit(line, ' ');
			check_room(str, *rooms);
			*rooms = add_end(*rooms, str[0], ft_atoi(str[1]), ft_atoi(str[2]));
			free_array(str);
		}
		free(line);
	}
	free(line);
	return (info);
}
