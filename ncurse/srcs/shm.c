/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:39:27 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 14:47:52 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ncurse.h>

int				init_shm(int size, char *name, int key_int)
{
	key_t		key;
	int			shmid;

	if ((key = ftok(name, (key_t)key_int)) == -1)
		return (ERROR_LEMIPC_NCURSE);
	if ((shmid = shmget(key, size, SHM_FLAG)) == - 1)
		return (ERROR_LEMIPC_NCURSE);
	return (shmid);
}

int				free_shm(int shmid)
{
	if ((shmctl(shmid, IPC_RMID, 0)) == -1)
		return (ERROR_LEMIPC_NCURSE);
	return (0);
}
