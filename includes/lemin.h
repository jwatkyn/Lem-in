/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

typedef struct s_links t_links;
typedef struct s_room t_room;
typedef struct s_path t_path;

struct				s_links
{
	char			**link;
	struct s_links	*next;
};

struct 				s_path
{
	char			*door;
	int				ant;
	struct s_path	*next;
	struct s_path	*prev;
};

typedef struct		s_paths
{
	t_path			*path;
	t_room			*rooms;
	struct s_paths	*next;
}					t_paths;

struct				s_room
{
	char			*room;
	int				x;
	int				y;
	int				visited;
	char			**neighbours;
	int				no_neighbours;
	struct s_room	*next;
};

typedef struct		s_info
{
	int				ants;
	int				cur_ant;
	int				stt;
	int				ed;
	int				paths;
	int				link_number;
	char			*start;
	char			*end;
	t_links			*links;
	t_room			*rooms;
}					t_info;

typedef struct		s_route
{
	char			*content;
	struct s_route	*next;
}					t_route;

t_info		*parsing(t_info *info, t_room **rooms, t_links **links);
t_room		*create(char *val, int x, int y);
t_room		*add_end(t_room *head, char *val, int x, int y);
t_room		*add_begin(t_room *head, char *val, int x, int y);
t_room		*del_end(t_room *head);
t_room		*del_begin(t_room *head);
t_links		*add_link(t_links *links, char *line, t_room *rooms);
t_room		*get_neighbour(t_room *rooms, t_links *links, t_info *info);
t_paths		*find_paths(t_info **info);
t_path		*create_path(char *val);
t_paths		*dijkstra(t_paths *paths, char *end, char *start);
t_room		*delete_current(t_room *rooms, t_room *del);
t_room		*remove_room(t_room *rooms, char *door);
t_room		*remove_rooms(t_room *rooms, t_path *paths);
int			visited(t_paths *paths, char *val);
int			no_paths(t_info *info);
void		send_ants(t_info *info, t_paths *paths);
t_path		*path_end(t_paths *paths);
void		free_rooms(t_info **info);
void		free_array(char **array);
void		free_links(t_info **info);
void		free_paths(t_paths **temp);
void		error(void);

#endif
