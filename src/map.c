/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 21:05:02 by nperrin           #+#    #+#             */
/*   Updated: 2015/05/14 19:21:37 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pac_man_def.h"
#include <stdio.h>

t_tile 	g_tile[N_TILE] =
{
	{VOID},
	{SOLID},
	{GHOST_DOOR}
};

void	init_maze_surface(SDL_Surface *dst, t_map map, t_tile tile[N_TILE]
			, SDL_Surface *content_pic[N_CONTENT])
{
	SDL_Rect	dst_rec;
	int			i;
	int			j;

	dst_rec.h = CASE_SIZE;
	dst_rec.w = CASE_SIZE;
	dst_rec.x = 0;
	for (i = 0; i < N_CASE_W; i++)
	{
		dst_rec.y = 0;
		for (j = 0; j < N_CASE_H; j++)
		{
			dst_rec.y += CASE_SIZE;
			SDL_BlitSurface(tile[map[j][i].id].pic, NULL, dst, &dst_rec);
			if (content_pic[map[j][i].content])
				SDL_BlitSurface(
					content_pic[map[j][i].content], NULL,
					dst, &dst_rec);
		}
		dst_rec.x += CASE_SIZE;
	}
}

int		load_maze(const char *path, t_map_case *map)
{
	unsigned	i;
	unsigned	buf;
	FILE		*map_file;

	if (!(map_file = fopen(path, "r")))
		return (-1);
	for (i = 0; i < (N_CASE_W * N_CASE_H); i++)
	{
		if (fscanf(map_file, "%2u", &buf) != 2)
		{
			fclose(map_file);
			return (-1);
		}
		if ((map[i].id = buf) >= N_TILE)
			return (-1);
	}
	if (fclose(map_file) != 0)
		return (-1);
	return (0);
}
