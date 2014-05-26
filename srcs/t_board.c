/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_board.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 11:20:41 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 11:49:29 by jponcele         ###   ########.fr       */
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
	if (player->first == 1)
		board->n = 1;
	else
		board->n = board->n + 1;
	return (board);
}

int								free_board(t_player *player)
{
	player->board->n = player->board->n - 1;
	if ((shmdt(player->board)) == -1)
		return (ERROR_LEMIPC);
	return (0);
}
