/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 17:44:54 by nperrin           #+#    #+#             */
/*   Updated: 2015/05/14 19:32:50 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pac_man.h"

static void		change_direction___(t_pac_man *pac_man, t_map map, t_tile tile[N_TILE])
{
	t_point	next_pos;


	if (pac_man->next_direction != NO_DIRECTION)
	{
		next_pos = add_point(pac_man->map_pos, g_move[pac_man->next_direction]);
		if (!case_is_solide(map[next_pos.y][next_pos.x], tile))
		{
			pac_man->direction = pac_man->next_direction;
			return ;
		}
	}
	if (pac_man->direction != NO_DIRECTION)
	{
		next_pos = add_point(pac_man->map_pos, g_move[pac_man->direction]);
		if (case_is_solide(map[next_pos.y][next_pos.x], tile))
			pac_man->direction = NO_DIRECTION;
	}
}

static void		move_case_axe(int *sub_pos, int *map_pos)
{
	if (*sub_pos < 0)
	{
		*sub_pos = CASE_SIZE - 1;
		(*map_pos)--;
	}
	else if (*sub_pos >= CASE_SIZE)
	{
		*sub_pos = 0;
		(*map_pos)++;
	}
}

void			erase_pac_man(t_point pos, SDL_Surface *maze, SDL_Surface *game)
{
	SDL_Rect	rec;

	rec.w = PAC_MAN_SIZE;
	rec.h = PAC_MAN_SIZE;
	rec.x = pos.x - (PAC_MAN_SIZE / 2);
	rec.y = pos.y - (PAC_MAN_SIZE / 2);
	SDL_BlitSurface(maze, &rec, game, &rec);
}

void			print_pacman(t_point pos)

void			move_pac_man(t_pac_man *pac_man, t_map map, t_tile tile[N_TILE])
{
	if (ABS(pac_man->sub_pos.x) == (CASE_SIZE / 2)
		|| ABS(pac_man->sub_pos.y) == (CASE_SIZE / 2))
			change_direction___(pac_man, map, tile);
	pac_man->sub_pos = add_point(pac_man->sub_pos, g_move[pac_man->direction]);
	pac_man->abs_pos = add_point(pac_man->abs_pos, g_move[pac_man->direction]);
	pac_man->sub_pos = add_point(pac_man->sub_pos, g_move[pac_man->direction]);
	move_case_axe(&pac_man->sub_pos.x, &pac_man->map_pos.x);
	move_case_axe(&pac_man->sub_pos.y, &pac_man->map_pos.y);
}
