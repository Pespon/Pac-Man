/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 19:06:05 by nperrin           #+#    #+#             */
/*   Updated: 2015/05/14 19:24:47 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pac_man.h"

static int		alloc_tile___(t_tile tile[N_TILE])
{
	int		i;

	i = 0;
	while (i < N_TILE)
	{
		if (!(tile[i].pic = SDL_CreateRGBSurface(0, 220, 180, 32, 0, 0, 0, 0)))
			break ;
		i++;
	}
	if (i == N_TILE)
		return (0);
	while (i >= 0)
		SDL_FreeSurface(tile[i--].pic);
	return (-1);
}

static void		copy_tile___(SDL_Surface *tile_set_surface, t_tile tile[N_TILE])
{
	int				i;
	SDL_Rect		src_rec;

	src_rec.w = CASE_SIZE;
	src_rec.h = CASE_SIZE;
	src_rec.y = 0;
	src_rec.x = 0;
	for (i = 0; i < N_TILE; i++)
	{
		SDL_BlitSurface(tile_set_surface, &src_rec, tile[i].pic, NULL);
		src_rec.x += CASE_SIZE;
	}
}

int				load_tile(const char *path, t_tile tile[N_TILE])
{
	SDL_Surface		*tile_set_surface;


	if (!(tile_set_surface = SDL_LoadBMP(path)))
		return (-1);
	if (tile_set_surface->h < CASE_SIZE || tile_set_surface->w < CASE_SIZE * N_TILE)
	{
		SDL_FreeSurface(tile_set_surface);
		return (-1);
	}
	if (alloc_tile___(tile) == -1)
	{
		SDL_FreeSurface(tile_set_surface);
		return (-1);
	}
	return (0);
}
