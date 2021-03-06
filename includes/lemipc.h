/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lempic.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:13:26 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 17:42:55 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include					<libft.h>
# include					<signal.h>
# include					<sys/ipc.h>
# include					<sys/types.h>
# include					<sys/msg.h>
# include					<sys/sem.h>
# include					<sys/shm.h>
# include					<time.h>

# define USAGE				"usage: lemipc <team number>"

# define ERROR_LEMIPC		ft_error("lemipc", __FILE__, __LINE__)

# define SHM_SIZE			4096 * 8
# define SHM_FILE			"./game/board"
# define SHM_FLAG			IPC_CREAT | SHM_R | SHM_W
# define SEM_FLAG			IPC_CREAT | SHM_R | SHM_W
# define MSG_FLAG			IPC_CREAT | SHM_R | SHM_W

# define X					20
# define Y					15

# define MAX_TEAM			7
# define MAX_ROUND			100

enum						e_dir
{
	UP, RIGHT, DOWN, LEFT
};

typedef struct				s_board
{
	int						n;
	int						map[Y][X];
	pid_t					pid;
	int						first[MAX_TEAM];
	int						dest[MAX_TEAM];
}							t_board;

typedef struct				s_player
{
	int						team;
	int						first;
	int						shmid;
	int						semid;
	int						msgid[MAX_TEAM];
	t_board					*board;
	int						curx;
	int						cury;
	int						first_team;
	int						last_dir;
}							t_player;

/*
**							check_input.c
*/

int							check_input(int ac, char **av);

/*
**							t_player.c
*/

t_player					*init_player(int team);
t_player					*init_player2(t_player *player);
int							put_player(t_board *board, t_player *player);
int							free_player(t_player *player);

/*
**							shm.c
*/

int							init_shm(t_player *player,
											int size, char *name, int key_int);
int							free_shm(int shmid);

/*
**							sem.c
*/

int							init_sem(char *name, int key_int);
int							free_sem(int semid);

/*
**							msg.c
*/

int							init_msg(t_player *player, char *name);
int							free_msg(t_player *player);

/*
**							lock.c
*/

int							lock(int semid);
int							unlock(int semid);

/*
**							t_board.c
*/

t_board						*init_board(t_player *player);
void						start_board(t_board *board, t_player *player);
void						init_first(t_board *board);
void						init_dest(t_board *board);
int							free_board(t_player *player);

/*
**							wait_ncurse.c
*/

void						wait_ncurse(t_player *player);

/*
**							loop.c
*/

void						loop(t_player *player);

/*
**							select_dest.c
*/

int							select_dest(t_player *player);
int							get_dest(t_player *player, int x, int y);
int							get_dest_loop(t_player *player,
														int dest, int x, int y);

/*
**							checks.c
*/

int							check(t_board *board, int x, int y, int team);
int							check_end(int end, int dest);

/*
**							get_dir.c
*/

int							get_dir(t_player *player, int dest);

/*
**							move.c
*/

int							move(t_player *player, int dir, int x, int y);
int							move2(t_player *player, int dir, int x, int y);
int							is_valid(t_player *player, int x, int y, int dir);

/*
**							check_dead.c
*/

int							check_dead(t_player *player, int x, int y);
int							*clean_tab(int *tab);
int							check_dead2(t_player *player, int **tab, int x,
		int y);
int							is_valid_for_dead(int x, int y);

/*
**							check_end.c
*/

int							check_end_game(t_player *player);

#endif
