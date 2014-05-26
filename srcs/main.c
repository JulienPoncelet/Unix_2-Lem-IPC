/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 10:12:28 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 12:03:09 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int							main(int ac, char **av)
{
	t_player				*player;

	ac--;
	av++;
	check_input(ac, av);
	if (!(player = init_player(ft_atoi(av[0]))))
		return (ERROR_LEMIPC);
	sleep(10);
	free_player(player);
	return (EXIT_SUCCESS);
}
