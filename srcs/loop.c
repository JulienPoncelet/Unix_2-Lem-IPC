/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 16:54:21 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 17:44:51 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

void					loop(t_player *player)
{
	int					end;
	int					dest;
	int					dir;
	int					k;

	k = 0;
	end = 0;
	while (!end && k++ < MAX_ROUND)
	{
		lock(player->semid);
		end = check_dead(player, player->curx - 1, player->cury - 1);
		if (!end)
		{
			dest = select_dest(player);
			if (dest != -2)
			{
				dir = get_dir(player, dest);
				move(player, dir, player->curx, player->cury);
				player->last_dir = dir;
			}
		}
		unlock(player->semid);
		end = (end) ? end : check_end_game(player);
		sleep(1);
	}
}
