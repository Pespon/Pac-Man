/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 17:52:39 by nperrin           #+#    #+#             */
/*   Updated: 2015/05/14 17:58:17 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pac_man.h"

t_point		set_point(int x, int y)
{
	t_point		pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

t_dpoint	set_dpoint(double x, double y)
{
	t_dpoint		pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}
