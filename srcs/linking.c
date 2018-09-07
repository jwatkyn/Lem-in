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

t_links		*create_links(char **val)
{
	t_links	*new;

	new = (t_links *)malloc(sizeof(t_links));
	new->link = val;
	new->next = NULL;
	return (new);
}

t_links	*add_link(t_links *links, char *line)
{
	t_links	*new;
	t_links	*temp;

	new = create_links(ft_strsplit(line, '-'));
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