/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_man_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:09:22 by nperrin           #+#    #+#             */
/*   Updated: 2015/05/14 19:21:12 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAC_MAN_DEF_H
# define PAC_MAN_DEF_H

# include <SDL2/SDL.h>

# ifndef DABS
#  define DABS(D)	(((D) >= 0.0) ? (D) : -(D))
# endif

# ifndef ABS
#  define ABS(X)	(((X) >= 0) ? (X) : -(X))
# endif

/* map_case content */
# define NOTHING	0
# define COOKIE		1
# define BIG_COOKIE	2

/* direction */
# define UP			0
# define RIGHT		1
# define DOWN		2
# define LEFT		3
# define NO_DIRECTION	4

/* status */
# define ATTACK		0
# define SCARED		1
# define DEAD		2
# define DANCE		3

/* tile type*/
# define VOID		0
# define SOLID		1
# define GHOST_DOOR	2

/* MAP CONST */

# define N_CASE_H		36
# define N_CASE_W		28

# define N_TILE			3
# define N_CONTENT		3

# define CASE_SIZE		32
# define PAC_MAN_SIZE	CASE_SIZE
# define GHOST_SIZE		CASE_SIZE

# define PIX_MAP_H (N_CASE_H * CASE_SIZE)
# define PIX_MAP_W (N_CASE_W * CASE_SIZE)

# define SCREEN_H PIX_MAP_H
# define SCREEN_W PIX_MAP_W

typedef struct		s_dpoint
{
	double			x;
	double			y;
}					t_dpoint;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_map_case
{
	unsigned		content;
	unsigned		id;
}					t_map_case;

typedef t_map_case	t_map[N_CASE_H][N_CASE_W];

typedef struct		s_tile
{
	unsigned		type;
	SDL_Surface		*pic;
}					t_tile;

typedef struct		s_ghost
{
	unsigned		direction;
	t_point			map_pos;
	t_point			sub_pos;
	t_point			abs_pos;
	t_point			dance_target;
	unsigned		status;
	unsigned		scared_cout;
}					t_ghost;

typedef struct		s_pac_man
{
	unsigned		direction;
	unsigned		next_direction;
	t_point			map_pos;
	t_point			sub_pos;
	t_point			abs_pos;
	unsigned		is_powered;
	unsigned		powered_count;
}					t_pac_man;

typedef struct		s_game_data
{
	unsigned		score;
	unsigned		level;
	t_ghost			*ghost[5];
	t_pac_man		pac_man;
	t_map			*map;
}					t_game_data;

#endif
