/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 17:16:15 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 18:27:55 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int							check(t_board *board, int x, int y, int team)
{
	if (x < 0 || x >= X || y < 0 || y >= Y)
		return (-1);
	if (board->map[y][x] != 0 && board->map[y][x] != team)
		return (y * Y + x);
	return (-1);
}

int							check_end(int end, int dest)
{
	if (dest >= X || dest >= Y)
		return (-2);
	return (end);
}
