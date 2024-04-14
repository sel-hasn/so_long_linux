/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:08:27 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/02 03:22:47 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cheack_first_end_last(t_list *list, char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	else if (s[0] == '\0')
		find_error1(list, 3);
	while (s[i])
	{
		if (s[i] != '1')
			find_error1(list, 3);
		i++;
	}
}

void	cheack_elment(t_list *lst, int exit_c, int coll_c, int player_c)
{
	int 	i;
	int 	j;

	i = 0;
	while (lst->map[i] != NULL)
	{
		j = 0;
		while (lst->map[i][j] != '\0')
		{
			if (lst->map[i][j] == 'E')
				exit_c++;
			else if (lst->map[i][j] == 'C')
				coll_c++;
			else if (lst->map[i][j] == 'P')
			{
				lst->p_y = i;
				lst->p_x = j;
				player_c++;
			}
			j++;
		}
		i++;
	}
	if (exit_c != 1 || player_c != 1 || coll_c < 1)
		find_error1(lst, 8);
}

char	**get_map(int	fd)
{
	char	*s;
	char	*str;
	char	**map;

	str = NULL;
	s = get_next_line(fd);
	// printf("%s", s);
	// sleep(1);
	if (s == NULL)
		find_error(str, s, 1);
	else if (s[0] == '\n' || s[0] == ' ' || s[0] == '\t')
		find_error(str, s, 1);
	while (s != NULL)
	{
		str = ft_strjoin(str, s);
		free(s);
		s = get_next_line(fd);
		if ((s != NULL && s[0] == '\n') 
		|| (str[ft_strlen(str) - 1] == '\n' && s == NULL))
			find_error(str, s, 2);
	}
	map = ft_split(str, '\n');
	if (map == NULL)
		return (NULL);
	return (map);
}

void	cheack_middle(t_list *list, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '1')
			i++;
		else if (s[i] == '0')
			i++;
		else if (s[i] == 'P')
			i++;
		else if (s[i] == 'E')
			i++;
		else if (s[i] == 'C')
			i++;
		else
			find_error1(list, 5);
	}
	if (s[0] != '1' || s[ft_strlen(s) - 1] != '1')
		find_error1(list, 11);
}
// void print_map(char **map)
// {
// 	while(*map)
// 		printf("map:%s\n",*(map++));
// }

void	parsing(t_list	*list, int fd)
{

	int		i;

	i = 0;
	list->map = get_map(fd);
	cheack_first_end_last(list, list->map[i]);
	while (list->map[i + 1] != NULL)
	{
		cheack_middle(list, list->map[i]);
		i++;
	}
	cheack_first_end_last(list, list->map[i]);
	cheack_elment(list, 0, 0, 0);
	cheack_all_len(list);
	list->map_copy = creat_map_copy(list->map);
	if (!(list->map))
		find_error1(list, 9);
	cheack_with_flood_fill(list, 0, 0);
	// print_map(list->map);
}
