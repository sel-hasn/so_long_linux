/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_handl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:30:42 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/04 16:00:10 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_enemy_is_N(t_list *list, int i, int j)
{
	if ((list->map[i - 1][j] == '0' || list->map[i - 1][j] == 'P')
	&& list->En_move_nb % 2 == 0)
		ft_enemy_move_up(list, j, i);
	else if ((list->map[i + 1][j] == '0' || list->map[i + 1][j] == 'P')
	&& list->En_move_nb % 2 == 0)
		ft_enemy_move_down(list, j, i);
	else if ((list->map[i][j + 1] == '0' || list->map[i][j + 1] == 'P')
	&& list->En_move_nb % 2 == 0)
		ft_enemy_move_right(list, j, i);
	else if ((list->map[i][j - 1] == '0' || list->map[i][j - 1] == 'P')
	&& list->En_move_nb % 2 == 0)
		ft_enemy_move_left(list, j, i);
}

void	ft_enemy_move(t_list *list)
{
	int i;
	int j;

	i = 0;
	while(list->map[i] != NULL)
	{
		j = 0;
		while(list->map[i][j])
		{
			if (list->map[i][j] == 'Y')
			{
				if ((list->map[i][j + 1] == '0' || list->map[i][j + 1] == 'P') 
				&& list->En_move_nb % 2 != 0)
					ft_enemy_move_right(list, j, i);
				else if ((list->map[i][j - 1] == '0' || list->map[i][j - 1] == 'P')
				&& list->En_move_nb % 2 != 0)
					ft_enemy_move_left(list, j, i);
				else if ((list->map[i - 1][j] == '0' || list->map[i - 1][j] == 'P')
				&& list->En_move_nb % 2 != 0)
					ft_enemy_move_up(list, j, i);
				else if ((list->map[i + 1][j] == '0' || list->map[i + 1][j] == 'P')
				&& list->En_move_nb % 2 != 0)
					ft_enemy_move_down(list, j, i);
			}
			else if (list->map[i][j] == 'N')
                ft_enemy_is_N(list, i, j);
			j++;
		}
		i++;
	}
}

int     ft_handel_enemy(t_list *list)
{
	static int i;

	list->En_count = 1;
	i++;
	if (i == 90000)
	{
		list->En_move_nb++;
		ft_enemy_move(list);
		i = 0;
	}
	return (0);
}

void    convert_myenemy_img(t_list *list)
{
	int x = 65;
	int i;

	i = 0;
	list->En_md = mlx_xpm_file_to_image(list->mlx, "img/en_md.xpm", &x , &x);
	list->En_ml = mlx_xpm_file_to_image(list->mlx, "img/en_ml.xpm", &x , &x);
	list->En_mr = mlx_xpm_file_to_image(list->mlx, "img/en_mr.xpm", &x , &x);
	list->En_mu = mlx_xpm_file_to_image(list->mlx, "img/en_mu.xpm", &x , &x);
	if (!list->En_mu || !list->En_ml || !list->En_mr || !list->En_md)
	{
		write (2, "Error\ncan't convert .xpm to image \n", 36);
		while (list->map[i] != NULL)
			free(list->map[i++]);
		free(list->map);
		exit (1);
	}
}

void	put_enemy_towin(t_list *list)
{
	int i;
	int j;

	i = 0;
	convert_myenemy_img(list);
	while(list->map[i] != NULL)
	{
		j = 0;
		while(list->map[i][j] != '\0')
		{
			if (list->map[i][j] == 'Y')
				mlx_put_image_to_window(list->mlx, list->win, list->Player_move_right, j * 65, i * 65);
			j++;
		}
		i++;
	}
}
