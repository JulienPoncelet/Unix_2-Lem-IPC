/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:37:01 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 16:15:52 by jponcele         ###   ########.fr       */
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
	if ((player->semid = init_sem(SHM_FILE, 42)) == FT_ERROR)
	{
		ERROR_LEMIPC;
		return (NULL);
	}
	return (init_player2(player));
}

t_player						*init_player2(t_player *player)
{
	if ((init_msg(player, SHM_FILE)) == FT_ERROR)
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

int								put_player(t_board *board, t_player *player)
{
	int							end;
	int							x;
	int							y;

	end = 0;
	srand(time(0));
	while (!end)
	{
		x = rand() % X;
		y = rand() % Y;
		if (board->map[y][x] == 0)
		{
			board->map[y][x] = player->team;
			player->curx = x;
			player->cury = y;
			end = 1;
		}
	}
	player->first_team = (board->first[player->team - 1]) ? 0 : 1;
	board->first[player->team - 1] = 1;
	return (0);
}

int								free_player(t_player *player)
{
	int							last;

	lock(player->semid);
	last = (player->board->n == 1) ? 1 : 0;
	player->board->n--;
	player->board->map[player->cury][player->curx] = 0;
	ft_putstr("Player left: ");
	ft_putnbrendl(player->board->n);
	unlock(player->semid);
	if (last)
	{
		kill(player->board->pid, SIGINT);
		free_board(player);
		free_msg(player);
		free_sem(player->semid);
		free_shm(player->shmid);
	}
	free(player);
	return (0);
}
