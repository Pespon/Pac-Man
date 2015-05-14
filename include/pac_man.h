/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_man.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:09:15 by nperrin           #+#    #+#             */
/*   Updated: 2015/05/14 19:21:47 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAC_MAN_H
# define PAC_MAN_H

# include "pac_man_def.h"

extern t_point	g_move[5];

t_point			set_point(int x, int y);
t_dpoint		set_dpoint(double x, double y);

# define		add_point(p1, p2) (set_point((p1).x + (p2).x, (p1).y + (p2).y))
# define		sub_point(p1, p2) (set_point((p1).x - (p2).x, (p1).y - (p2).y))
# define		mul_point(p1, p2) (set_point((p1).x * (p2).x, (p1).y * (p2).y))

# define		case_is_solide(map_case, tile)	((tile)[(map_case).id].type != VOID)

int				load_tile(const char *path, t_tile tile[N_TILE]);
void			move_pac_man(t_pac_man *pac_man, t_map map, t_tile tile[N_TILE]);

void			init_maze_surface(SDL_Surface *dst, t_map map, t_tile tile[N_TILE]
									, SDL_Surface *content_pic[N_CONTENT]);
int				load_maze(const char *path, t_map_case *map);

#endif
