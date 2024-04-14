/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:07:29 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/03 22:14:54 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_list *list)
{
	int i;

	i = 0;
	while (list->map[i] != NULL)
	{
		free(list->map[i]);
		i++;
	}
	free(list->map);
}

size_t	wordcount(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

char	**freeword(char **str, size_t idx)
{
	while (idx > 0)
	{
		free(str[idx - 1]);
		idx--;
	}
	free(str);
	return (NULL);
}

char	**mysplit(char **wd, char *st, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (st[j] && i < wordcount(st, c))
	{
		while (st[j] == c)
			j++;
		len = 0;
		while (st[j + len] != '\0' && st[j + len] != c)
			len++;
		wd[i] = ft_substr(st, j, len);
		if (!wd[i])
			return (free(st), freeword(wd, i));
		j = j + len;
		i++;
	}
	wd[i] = NULL;
	free(st);
	return (wd);
}

char	**ft_split(char *s, char c)
{
	char	**word;

	if (!s)
		return (NULL);
	word = (char **)malloc (sizeof(char *) * (wordcount(s, c) + 1));
	if (!word)
		return (NULL);
	return (mysplit(word, s, c));
}