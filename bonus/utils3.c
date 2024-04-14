/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:41:57 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/01 21:27:18 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_ending_by_ber(char *map_name)
{
	int len;
	int i;
	char *s;
	
	i = 0;
	len = (ft_strlen(map_name) - 4);
	s = ft_strdup(".ber");
	while (map_name[len])
	{
		if (s[i] == map_name[len])
			i++;
		len++;
	}
	if (s[i] != '\0')
	{
		free (s);
		return (0);
	}
	free (s);
	return (1);
}

void	cheack_all_len(t_list *list)
{
	int i;

	i = 0;
	while (list->map[i] != NULL)
	{
		if (list->map[i + 1] == NULL)
			break ;
		else if (ft_strlen(list->map[i]) != ft_strlen(list->map[i + 1]))
			find_error1(list, 8);
		i++;
	}
	list->size_x = ft_strlen(list->map[i]);
	list->size_y = i + 1;
}

char	**creat_map_copy(char **map)
{
	int i;
	char **map_copy;

	i = 0;
	while (map[i] != NULL)
		i++;
	map_copy = malloc(sizeof(char *)*(i + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
			return (freeword(map_copy, i));
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void flood_feel(char **map, int y, int x)
{
	if(map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'T'
		|| map[y][x] == 'Y')
		return ;
	if(map[y][x] == 'E')
	{
		map[y][x] = 'T';
		return ;
	}
	map[y][x] = 'X';
	flood_feel(map,y,x+1);
	flood_feel(map,y,x-1);
	flood_feel(map,y+1,x);
	flood_feel(map,y-1,x);
}

// static void print_map(char **map)
// {
// 	while(*map)
// 		printf("map_afther_flood_fill:%s\n",*(map++));
// }

void	cheack_with_flood_fill(t_list *lst, int c_countr, int t_countr)
{
	int i;
	int j;

	i = 0;
	flood_feel(lst->map_copy, lst->p_y, lst->p_x);
	while (lst->map_copy[i])
	{
		j = 0;
		while (lst->map_copy[i][j])
		{
			if (lst->map_copy[i][j] == 'C')
				c_countr++;
			else if (lst->map_copy[i][j] == 'T')
				t_countr++;
			j++;
		}
		i++;
	}
	if (c_countr != 0 || t_countr != 1)
	{
		freeword(lst->map_copy, i);
		find_error1(lst, 10);
	}
	// print_map(lst->map_copy);
	freeword(lst->map_copy, i);
}
