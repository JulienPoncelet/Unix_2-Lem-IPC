/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 18:17:33 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 16:59:35 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int								abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int								get_dir(t_player *player, int dest)
{
	int							x;
	int							y;
	int							dx;
	int							dy;
	int							delta;

	x = dest % Y;
	y = dest / Y;
	dx = player->curx - x;
	dy = player->cury - y;
	dx = (!dx) ? dy - 1 : dx;
	dy = (!dy) ? dx - 1 : dy;
	delta = (abs(dx) > abs(dy)) ? dx : dy;
	if (delta == dx)
	{
		if (dx > 0)
			return (LEFT);
		return (RIGHT);
	}
	else if (dy > 0)
		return (UP);
	return (DOWN);
}
