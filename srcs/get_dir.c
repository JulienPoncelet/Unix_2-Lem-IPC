/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 18:17:33 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 18:33:22 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int								get_dir(t_player *player, int dest)
{
	int							x;
	int							y;

	x = dest % Y;
	y = dest / Y;
	printf("Check dir from [%d][%d] to [%d][%d]\n", player->cury, player->curx, y, x);
	sleep(5);
	return (0);
}
