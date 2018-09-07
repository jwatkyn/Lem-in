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

t_info	*parsing(t_info *info, t_room **rooms, t_links **links)
{
	char	*line;
	char	**str;

	while (get_next_line(0, &line))
	{
		if (!(info->ants) && ft_atoi(line))
		{
			info->ants = ft_atoi(line);
			ft_strdel(&line);
			continue ;
		}
		if (info->stt == 1)
		{
			info->stt = 2;
			str = ft_strsplit(line, ' ');
			info->start = ft_strdup(str[0]);
			free_array(str);
		}
		if (info->ed == 1)
		{
			info->ed = 2;
			str = ft_strsplit(line, ' ');
			info->end = ft_strdup(str[0]);
			free_array(str);
		}
		if (line && line[0] == '#')
		{
			if (!ft_strcmp(line, "##start"))
				info->stt = 1;
			else if (!ft_strcmp(line, "##end"))
				info->ed = 1;
			ft_strdel(&line);
			continue ;
		}
		if (ft_strchr(line, '-') && ft_strncmp(line, "#", 1))
		{
			info->link_number++;	
			*links = add_link(*links, line);
		}
		else
		{
			str = ft_strsplit(line, ' ');
			*rooms = add_end(*rooms, str[0]);
			free_array(str);
		}
		free(line);
	}
	free(line);
	return (info);
}