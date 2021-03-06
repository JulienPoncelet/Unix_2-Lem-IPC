/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_dest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 17:02:36 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 17:41:58 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int						select_dest(t_player *player)
{
	int					dest;
	int					end;

	end = -1;
	if (!player->first_team)
		end = player->board->dest[player->team - 1];
	end = (end == -2) ? -1 : end;
	dest = 1;
	while (end == -1)
		end = get_dest_loop(player, dest++, player->curx, player->cury);
	if (player->first_team)
		player->board->dest[player->team - 1] = end;
	return (end);
}

int						get_dest_loop(t_player *player, int dest, int x, int y)
{
	int					i;
	int					j;
	int					k;
	int					end;

	end = -1;
	i = x - dest;
	j = y - dest;
	k = 0;
	while (k++ < 2 * dest + 1 && end == -1)
		end = check(player->board, i++, j, player->team);
	i = x + dest;
	k = 0;
	while (k++ < 2 * dest + 1 && end == -1)
		end = check(player->board, i, j++, player->team);
	j = y + dest;
	k = 0;
	while (k++ < 2 * dest + 1 && end == -1)
		end = check(player->board, i--, j, player->team);
	i = x - dest;
	k = 0;
	while (k++ < 2 * dest + 1 && end == -1)
		end = check(player->board, i, j--, player->team);
	end = check_end(end, dest);
	return (end);
}
