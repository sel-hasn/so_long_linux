/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:31:33 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/04 15:48:17 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		ft_nbrlen(int i)
{
	int len;

	len = 0;
	if (i == 0 || i == 1)
		return (1);
	if (i < 0)
	{
		len++;
		i = i * -1;
	}
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int i)
{
	char *s;
	int len;

	len = ft_nbrlen(i);
	s = (char *)malloc(sizeof(char)*(len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (i < 0)
	{
		s[0] = '-';
		i = i * -1;
	}
	else if (i < 0)
		s[0] = '0';
	while (i != 0)
	{
		len--;
		s[len] = (i % 10) + '0';
		// printf("%c", ((i % 10) + '0'));
		i = i / 10;
	}
	return (s);
}
