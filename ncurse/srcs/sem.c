/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 12:01:03 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 14:42:46 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ncurse.h>

int							init_sem(char *name, int key_int)
{
	key_t					key;
	int						semid;
	union semun				u_semun;

	if ((key = ftok(name, (key_t)key_int)) == -1)
		return (ERROR_LEMIPC_NCURSE);
	if ((semid = semget(key, 1, SEM_FLAG | IPC_EXCL)) == -1)
	{
		if ((semid = semget(key, 1, SEM_FLAG)) == -1)
			return (ERROR_LEMIPC_NCURSE);
	}
	u_semun.val = 1;
	if ((semctl(semid, 0, SETVAL, u_semun)) == -1)
		return (ERROR_LEMIPC_NCURSE);
	return (semid);
}

int							free_sem(int semid)
{
	if ((semctl(semid, 0, IPC_RMID, 0)) == -1)
		return (ERROR_LEMIPC_NCURSE);
	return (0);
}
