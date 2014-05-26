/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 11:49:35 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 12:00:57 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int								check_input(int ac, char **av)
{
	if (ac != 1)
	{
		ft_putendl(USAGE);
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(av[0]) < 0 || ft_atoi(av[0]) > 7)
	{
		ft_putendl(USAGE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
