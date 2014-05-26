/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:03:19 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 13:32:44 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_strlen(const char *str)
{
	int			index;

	index = 0;
	if (str)
	{
		while (str[index])
			index++;
	}
	return (index);
}
