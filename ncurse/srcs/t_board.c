/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_board.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 11:20:41 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 16:19:09 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ncurse.h>

t_board							*init_board(t_ncurse *ncurse)
{
	if (!(ncurse->board = (t_board *)shmat(ncurse->shmid, 0, 0)))
	{
		ERROR_LEMIPC_NCURSE;
		return (0);
	}
	lock(ncurse->semid);
	ncurse->board->pid = getpid();
	unlock(ncurse->semid);
	return (ncurse->board);
}
