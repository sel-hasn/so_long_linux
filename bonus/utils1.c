/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:27:36 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/03 22:11:20 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dsize > 0)
	{
		while (src[i] != '\0' && dsize - 1 > i)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && j + 1 < (size - i))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}

int	ft_cmp(char *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	find_error(char *str, char *s, int i)
{
	if (!s && !str)
	{
		write (2, "Error\nEmpty map\n", 17);
		exit(1);
	}
	if (str != NULL)
		free(str);
	free(s);
	write (2, "Error\nIncorrect map\n", 21);
	exit(i);
}

void	find_error1(t_list *list, int i)
{
	int j;

	j = 0;
	if (i == 9)
	{
		write (2, "Error\ncan't alloc for map_copy\n", 32);
		exit (i);
	}
	else if (i == 10)
	{
		write (2, "Error\nInvalid path\n", 20);
		exit (i);
	}
	write (2, "Error\nIncorrect map\n", 21);
	if (list->map == NULL || list->map[j] == NULL)
		exit(i);
	free_map(list);
	exit(i);
}
