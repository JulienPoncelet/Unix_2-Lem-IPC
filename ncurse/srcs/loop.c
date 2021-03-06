/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 14:24:57 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 10:56:32 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ncurse.h>

void						loop(t_ncurse *ncurse)
{
	int						y;

	while (42)
	{
		y = 0;
		while (y < Y)
		{
			print_line(ncurse, y);
			y++;
		}
		print_row(y * 2);
		refresh();
		sleep(1);
	}
}

void						print_row(int y)
{
	int						x;

	x = 0;
	while (x < X * 3)
	{
		mvprintw(y, x++, "+");
		mvprintw(y, x++, "-");
		mvprintw(y, x++, "-");
	}
	mvprintw(y, x++, "+");
}

void						print_line(t_ncurse *ncurse, int y)
{
	int						j;
	int						x;
	int						team;

	j = y * 2;
	print_row(j++);
	x = 0;
	while (x < X * 3)
	{
		team = ncurse->board->map[y][x / 3];
		mvprintw(j, x++, "|");
		attron(COLOR_PAIR(team));
		mvprintw(j, x++, " ");
		if (team)
			mvprintw(j, x, "%d", (team));
		else
			mvprintw(j, x, " ");
		x++;
		attron(COLOR_PAIR(8));
	}
	mvprintw(j, x, "|");
}
