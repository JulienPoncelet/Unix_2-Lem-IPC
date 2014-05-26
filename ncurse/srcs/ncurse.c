/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 14:02:35 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 17:15:59 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ncurse.h>

t_ncurse					*init_ncurse(void)
{
	t_ncurse				*ncurse;

	ncurse = (t_ncurse *)malloc(sizeof(t_ncurse));
	if ((ncurse->shmid = init_shm(SHM_SIZE, SHM_FILE, 42)) == FT_ERROR)
	{
		ERROR_LEMIPC_NCURSE;
		return (0);
	}
	if ((ncurse->semid = init_sem(SHM_FILE, 42)) == FT_ERROR)
	{
		ERROR_LEMIPC_NCURSE;
		return (0);
	}
	if (!(ncurse->board = init_board(ncurse)))
	{
		ERROR_LEMIPC_NCURSE;
		return (0);
	}
	return (init_ncurse2(ncurse));
}

t_ncurse					*init_ncurse2(t_ncurse *ncurse)
{
	ncurse->win = initscr();
	noecho();
	start_color();
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_YELLOW);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_WHITE);
	return (ncurse);
}
