/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 13:54:53 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 16:10:35 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NCURSE_H
# define FT_NCURSE_H

#include <stdio.h>

# include						<libft.h>
# include						<ncurses.h>
# include						<sys/ipc.h>
# include						<sys/types.h>
# include						<sys/sem.h>
# include						<sys/shm.h>

# define ERROR_LEMIPC_NCURSE	ft_error("lemipc_ncurse", __FILE__, __LINE__)

# define X						20
# define Y						15

# define SHM_SIZE				4096 * 8
# define SHM_FILE				"./game/board"
# define SHM_FLAG				SHM_R | SHM_W
# define SEM_FLAG				SHM_R | SHM_W

# define MAX_TEAM				7

typedef struct					s_board
{
	int							n;
	int							map[Y][X];
	pid_t						pid;
	int							first[MAX_TEAM];
	int							dest[MAX_TEAM];
}								t_board;

typedef struct					s_ncurse
{
	WINDOW						*win;
	int							semid;
	int							shmid;
	t_board						*board;
}								t_ncurse;

/*
**								ncurses.c
*/

t_ncurse						*init_ncurse(void);
t_ncurse						*init_ncurse2(t_ncurse *ncurse);

/*
**								loop.c
*/

void							loop(t_ncurse *ncurse);
void							print_line(t_ncurse *ncurses, int y);
void							print_row(int y);

/*
**								shm.c
*/

int								init_shm(int size, char *name, int key_int);
int								free_shm(int shmid);

/*
**								sem.c
*/

int								init_sem(char *name, int key_int);
int								free_sem(int semid);

/*
**								t_board.c
*/

t_board							*init_board(t_ncurse *ncurse);

/*
**								lock.c
*/

int								lock(int semid);
int								unlock(int semid);

#endif
