/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_dest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 17:02:36 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 13:48:17 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int						select_dest(t_player *player)
{
	int					dest;
	int					end;

	dest = 1;
	end = -1;
	while (end == -1)
		end = get_dest_loop(player, dest++, player->curx, player->cury);
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
