/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 14:00:28 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 15:34:24 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int								init_msg(t_player *player, char *name)
{
	int							i;
	key_t						key;

	i = 0;
	while (i < MAX_TEAM)
	{
		if ((key = ftok(name, (key_t)i)) == -1)
			return (ERROR_LEMIPC);
		if ((player->msgid[i] = msgget(key, MSG_FLAG | IPC_EXCL)) == -1)
		{
			if ((player->msgid[i] = msgget(key, SEM_FLAG)) == -1)
				return (ERROR_LEMIPC);
		}
		i++;
	}
	return (0);
}

int							free_msg(t_player *player)
{
	int						i;

	i = 0;
	while (i < MAX_TEAM)
	{
		if ((msgctl(player->msgid[i], IPC_RMID, 0)) == -1)
			return (ERROR_LEMIPC);
		i++;
	}
	return (0);
}
