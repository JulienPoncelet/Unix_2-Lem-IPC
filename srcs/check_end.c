/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 12:04:21 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 12:16:08 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int							check_end_game(t_player *player)
{
	int						x;
	int						y;
	int						cur;

	y = 0;
	while (y < Y)
	{
		x = 0;
		while (x < X)
		{
			cur = player->board->map[y][x];
			if (cur && cur != player->team)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
