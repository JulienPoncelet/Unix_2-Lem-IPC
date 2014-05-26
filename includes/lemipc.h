/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lempic.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:13:26 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 12:03:07 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMPIC_H
# define LEMIPC_H

#include <stdio.h>

# include					<libft.h>
# include					<sys/ipc.h>
# include					<sys/types.h>
# include					<sys/shm.h>

# define USAGE				"usage: lemipc <team number>"

# define ERROR_LEMIPC		ft_error("lemipc", __FILE__, __LINE__)

# define SHM_SIZE			4096 * 8
# define SHM_FILE			"./game/board"
# define SHM_FLAG			IPC_CREAT | SHM_R | SHM_W

typedef struct				s_board
{
	int						n;
}							t_board;

typedef struct				s_player
{
	int						team;
	int						first;
	int						shmid;
	t_board					*board;
}							t_player;

/*
**							check_input.c
*/

int							check_input(int ac, char **av);

/*
**							t_player.c
*/

t_player					*init_player(int player);
int							free_player(t_player *player);

/*
**							shm.c
*/

int							init_shm(t_player *player,
											int size, char *name, int key_int);
int							free_shm(int shmid);

/*
**							t_board.c
*/

t_board						*init_board(t_player *player);
int							free_board(t_player *player);

#endif
