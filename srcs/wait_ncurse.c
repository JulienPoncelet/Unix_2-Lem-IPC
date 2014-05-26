/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_ncurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 13:34:23 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 17:32:03 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

void						wait_ncurse(t_player *player)
{
	int						end;

	ft_putendl("Launch lemipc_ncurse to start the war!");
	end = 0;
	while (!end)
	{
		lock(player->semid);
		if (player->board->pid != -1)
			end = 1;
		unlock(player->semid);
		sleep(1);
	}
}
