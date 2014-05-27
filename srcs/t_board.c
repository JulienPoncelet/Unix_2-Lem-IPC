/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_board.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 11:20:41 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 16:28:14 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

t_board							*init_board(t_player *player)
{
	t_board						*board;

	if (!(board = (t_board *)shmat(player->shmid, 0, 0)))
	{
		ERROR_LEMIPC;
		return (0);
	}
	lock(player->semid);
	if (player->first == 1)
		start_board(board, player);
	else
		board->n = board->n + 1;
	put_player(board, player);
	unlock(player->semid);
	return (board);
}

void							start_board(t_board *board, t_player *player)
{
	int							x;
	int							y;

	board->n = 1;
	y = 0;
	while (y < Y)
	{
		x = 0;
		while (x < X)
		{
			board->map[y][x] = 0;
			x++;
		}
		y++;
	}
	board->pid = -1;
	x = 0;
	while (x < MAX_TEAM)
	{
		board->first[x] = 0;
		board->dest[x] = -1;
		x++;
	}
	(void)player;
}

int								free_board(t_player *player)
{
	if ((shmdt(player->board)) == -1)
		return (ERROR_LEMIPC);
	return (0);
}
