/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 13:20:27 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 15:51:41 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ncurse.h>

int							lock(int semid)
{
	struct sembuf			semlock;

	semlock.sem_num = 0;
	semlock.sem_op = -1;
	semlock.sem_flg = 0;
	if ((semop(semid, &semlock, 1)) == -1)
		return (ERROR_LEMIPC_NCURSE);
	return (0);
}

int							unlock(int semid)
{
	struct sembuf			semunlock;

	semunlock.sem_num = 0;
	semunlock.sem_op = 1;
	semunlock.sem_flg = 0;
	if ((semop(semid, &semunlock, 1)) == -1)
		return (ERROR_LEMIPC_NCURSE);
	return (0);
}
