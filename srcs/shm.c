/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:39:27 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 13:51:00 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int				init_shm(t_player *player, int size, char *name, int key_int)
{
	key_t		key;
	int			shmid;

	if ((key = ftok(name, (key_t)key_int)) == -1)
		return (ERROR_LEMIPC);
	if ((shmid = shmget(key, size, SHM_FLAG | IPC_EXCL)) == -1)
	{
		if ((shmid = shmget(key, size, SHM_FLAG)) == -1)
			return (ERROR_LEMIPC);
	}
	else
		player->first = 1;
	return (shmid);
}

int				free_shm(int shmid)
{
	if ((shmctl(shmid, IPC_RMID, 0)) == -1)
		return (ERROR_LEMIPC);
	return (0);
}
