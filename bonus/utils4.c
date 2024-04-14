/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:31:33 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/04 15:48:17 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_c_num_e_pos(t_list *l)
{
	int i;
	int j;

	i = 0;
	l->c_count = 0;
	while (l->map[i] != NULL)
	{
		j = 0;
		while (l->map[i][j] != '\0')
		{
			if (l->map[i][j] == 'C')
				l->c_count++;
			else if (l->map[i][j] == 'E')
			{
				l->e_x = j;
				l->e_y = i;
			}
			j++;
		}
		i++;
	}
}

void	end_game(t_list *l,int i)
{
	int j;

	j = 0;
	while (l->map[j] != NULL)
	{
		free(l->map[j]);
		j++;
	}
	free(l->map);
	if (i == 0)
		write (1, "you win the game\n", 18);
	else if (i == 2)
	{
		write (1, "you lose the game\n", 19);
		exit (1);
	}
	exit (0);
}

void	ft_putnbr(int n)
{
	char c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		c = n + '0';
		write (1, &c, 1);
	}
}

void	put_images_towin(t_list *list)
{
	int i;
	int j;

	i = 0;
	while(list->map[i] != NULL)
	{
		j = 0;
		while(list->map[i][j] != '\0')
		{
			if (list->map[i][j] == 'P')
				mlx_put_image_to_window(list->mlx, list->win, list->Player_move_right, j * 65, i * 65);
			else if (list->map[i][j] == '1')
				mlx_put_image_to_window(list->mlx, list->win, list->Wall, j * 65, i * 65);
			else if (list->map[i][j] == '0')
				mlx_put_image_to_window(list->mlx, list->win, list->Background, j * 65, i * 65);
			else if (list->map[i][j] == 'C')
				mlx_put_image_to_window(list->mlx, list->win, list->Collectible, j * 65, i * 65);
			else if (list->map[i][j] == 'E')
				mlx_put_image_to_window(list->mlx, list->win, list->Closed_door, j * 65, i * 65);
			j++;
		}
		i++;
	}
}
