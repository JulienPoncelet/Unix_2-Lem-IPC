/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 10:45:00 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/27 13:21:23 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int						check_dead(t_player *player, int x, int y)
{
	int					i;
	int					j;
	int					*tab;
	int					end;

	tab = (int *)malloc(sizeof(int) * 7);
	tab = clean_tab(tab);
	j = 0;
	end = 0;
	while (j < 3 && !end)
	{
		i = 0;
		while (i < 3 && !end)
		{
			if (is_valid_for_dead(x + i, y + j))
				end = check_dead2(player, &tab, x + i, y + j);
			i++;
		}
		j++;
	}
	free(tab);
	return (end);
}

int						*clean_tab(int *tab)
{
	int					i;

	i = 0;
	while (i < 7)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int						check_dead2(t_player *player, int **tab, int x, int y)
{
	int					cur;
	int					*cur_tab;

	cur_tab = (int *)malloc(sizeof(int) * 7);
	cur_tab = *tab;
	cur = player->board->map[y][x];
	if (cur && cur != player->team)
	{
		if (cur_tab[cur - 1])
			return (1);
		cur_tab[cur - 1]++;
	}
	*tab = cur_tab;
	return (0);
}

int						is_valid_for_dead(int x, int y)
{
	if (x < 0 || x >= X || y < 0 || y >= Y)
		return (0);
	return (1);
}
