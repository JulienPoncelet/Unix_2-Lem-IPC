/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 16:54:21 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 18:33:35 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

void					loop(t_player *player)
{
	int					end;
	int					dest;
	int					dir;

	end = -3;
	while (end)
	{
		lock(player->semid);
		dest = select_dest(player);
		if (dest != -2)
		{
			dir = get_dir(player, dest);
		}
		unlock(player->semid);
		end++;
		sleep(1);
	}
}
