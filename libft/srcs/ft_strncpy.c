/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:10:46 by jponcele          #+#    #+#             */
/*   Updated: 2014/03/21 15:48:55 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		index;

	index = 0;
	while (index < len)
	{
		dst[index] = src[index];
		index++;
	}
	if (len != index)
		dst[index] = '\0';
	return (dst);
}
