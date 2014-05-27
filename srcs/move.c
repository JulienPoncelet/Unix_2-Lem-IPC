/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 13:40:35 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 13:42:37 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int								move(t_player *player, int dir, int x, int y)
{
	if (dir == UP)
	{
		y--;
		if (!(is_valid(player, x, y)))
			return (move(player, RIGHT, player->curx, player->cury));
	}
	if (dir == DOWN)
	{
		y++;
		if (!(is_valid(player, x, y)))
			return (move(player, LEFT, player->curx, player->cury));
	}
	return (move2(player, dir, x, y));
}

int								move2(t_player *player, int dir, int x, int y)
{
	if (dir == RIGHT)
	{
		x++;
		if (!(is_valid(player, x, y)))
			return (move(player, DOWN, player->curx, player->cury));
	}
	if (dir == LEFT)
	{
		x--;
		if (!(is_valid(player, x, y)))
			return (move(player, UP, player->curx, player->cury));
	}
	player->board->map[player->cury][player->curx] = 0;
	player->curx = x;
	player->cury = y;
	player->board->map[player->cury][player->curx] = player->team;
	return (0);
}

int								is_valid(t_player *player, int x, int y)
{
	if (x < 0 || x >= X || y < 0 || y >= Y)
		return (0);
	if (player->board->map[y][x])
		return(0);
	return (1);
}
