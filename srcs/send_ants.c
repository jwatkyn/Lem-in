/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semd_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_ant(int ant, char *room)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(room);
	ft_putchar(' ');
}

t_paths	*move_ants(t_paths *paths, int no_paths, t_info *info)
{
	int 	i;
	int		move;
	int		move1;
	t_path	*temp;
	t_paths	*temp1;

	i = -1;
	temp1 = paths;
	while (++i < no_paths)
	{
		temp = temp1->path;
		move = temp->ant;
		info->cur_ant++;
		if (info->cur_ant <= info->ants)
			temp->ant = info->cur_ant;
		else
			temp->ant = 0;
		while (temp->next)
		{
			temp = temp->next;
			move1 = temp->ant;
			temp->ant = move;
			move = move1;
		}
		while (temp->prev)
		{
			if (temp->ant > 0 && ft_strcmp(temp->door, info->start))
				print_ant(temp->ant, temp->door);
			temp = temp->prev;
		}
		temp1 = temp1->next;
	}
	return (paths);
}

t_path	*paths_end(t_path *path)
{
	t_path	*temp;

	temp = path;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	send_ants(t_info *info, t_paths *paths)
{
	int		j;
	int		flag;
	t_paths	*temp;

	flag = 1;
	while (flag)
	{
		j = info->paths;
		paths = move_ants(paths, j, info);
		ft_putendl("");
		temp = paths;
		while (1)
		{
			if (paths_end(temp->path)->ant == info->ants)
				flag = 0;
			if (!temp->next)
				break ;
			temp = temp->next;
		}
	}
}
