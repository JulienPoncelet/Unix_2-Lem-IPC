/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 13:55:53 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/26 18:17:15 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ncurse.h>

int								main(void)
{
	t_ncurse					*ncurse;

	if (!(ncurse = init_ncurse()))
	{
		ERROR_LEMIPC_NCURSE;
		return (EXIT_FAILURE);
	}
	loop(ncurse);
	endwin();
	return (EXIT_SUCCESS);
}
