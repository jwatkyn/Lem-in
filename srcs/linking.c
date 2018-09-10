/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_links2(char *str, t_room *rooms)
{
	t_room *temp;

	temp = rooms;
	while (temp)
	{
		if (!ft_strcmp(temp->room, str))
			return ; ;
		temp = temp->next;
	}
	error();
}

void	check_link(char **str, t_room *rooms)
{
	int		i;

	i = -1;
	while (str[++i])
		check_links2(str[i], rooms);
}

t_links		*create_links(char **val)
{
	t_links	*new;

	new = (t_links *)malloc(sizeof(t_links));
	new->link = val;
	new->next = NULL;
	return (new);
}

t_links	*add_link(t_links *links, char *line, t_room *rooms)
{
	t_links	*new;
	t_links	*temp;
	char	**str;

	str = ft_strsplit(line, '-');
	check_link(str, rooms);
	new = create_links(str);
	temp = links;
	if (links == NULL)
		links = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (links);
}