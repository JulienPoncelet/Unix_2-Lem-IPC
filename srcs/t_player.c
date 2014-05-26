/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:37:01 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 12:03:05 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

t_player						*init_player(int team)
{
	t_player					*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
	{
		ERROR_LEMIPC;
		return (NULL);
	}
	player->team = team;
	player->first = 0;
	if ((player->shmid = init_shm(player, SHM_SIZE, SHM_FILE, 42)) == FT_ERROR)
	{
		ERROR_LEMIPC;
		return (NULL);
	}
	if (!(player->board = init_board(player)))
	{
		ERROR_LEMIPC;
		return (NULL);
	}
	return (player);
}

int								free_player(t_player *player)
{
	int							last;

	last = (player->board->n == 1) ? 1 : 0;
	free_board(player);
	if (last)
		free_shm(player->shmid);
	free(player);
	return (0);
}
