/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:55:24 by jponcele          #+#    #+#             */
/*   Updated: 2014/03/26 17:04:35 by vgedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	index;

	new_str = NULL;
	if (str && f)
	{
		new_str = (char*)malloc(sizeof(*new_str) * (ft_strlen(str) + 1));
		index = 0;
		while (str[index] != '\0')
		{
			new_str[index] = f(index, str[index]);
			index++;
		}
		new_str[index] = '\0';
	}
	return (new_str);
}
