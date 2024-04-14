/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:30:42 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/04 16:00:10 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_move_up(t_list *l, int x, int y)
{
	if (l->map[y - 1][x] == 'P')
		end_game(l, 2);
	mlx_put_image_to_window(l->mlx, l->win, l->Background, x * 65, y * 65);
	mlx_put_image_to_window(l->mlx, l->win, l->Player_move_up, x * 65, (y - 1) * 65);
	// printf("befor:%s\n", l->map[y]);
	if (l->En_move_nb % 2 != 0)
		l->map[y - 1][x] = 'N';
	else
		l->map[y - 1][x] = 'Y';
	l->map[y][x] = '0';
	// printf("after:%s\n", l->map[y]);
}

void	ft_enemy_move_right(t_list *l, int x, int y)
{
	if (l->map[y][x + 1] == 'P')
		end_game(l, 2);
	mlx_put_image_to_window(l->mlx, l->win, l->Background, x * 65, y * 65);
	mlx_put_image_to_window(l->mlx, l->win, l->Player_move_right, (x + 1) * 65, y * 65);
	if (l->En_move_nb % 2 != 0)
		l->map[y][x + 1] = 'N';
	else
		l->map[y][x + 1] = 'Y';
	l->map[y][x] = '0';
}

void	ft_enemy_move_down(t_list *l, int x, int y)
{
	if (l->map[y + 1][x] == 'P')
		end_game(l, 2);
	mlx_put_image_to_window(l->mlx, l->win, l->Background, x * 65, y * 65);
	mlx_put_image_to_window(l->mlx, l->win, l->Player_move_down, x * 65, (y + 1) * 65);
	// mlx_put_image_to_window(l->mlx, l->win, l->En_md, x * 65, (y + 1) * 65);
	if (l->En_move_nb % 2 != 0)
		l->map[y + 1][x] = 'N';
	else
		l->map[y + 1][x] = 'Y';
	l->map[y][x] = '0';
}

void	ft_enemy_move_left(t_list *l, int x, int y)
{
	if (l->map[y][x - 1] == 'P')
		end_game(l, 2);
	mlx_put_image_to_window(l->mlx, l->win, l->Background, x * 65, y * 65);
	mlx_put_image_to_window(l->mlx, l->win, l->Player_move_left, (x - 1) * 65, y * 65);
	// mlx_put_image_to_window(l->mlx, l->win, l->En_ml, (x - 1) * 65, y * 65);
	if (l->En_move_nb % 2 != 0)
		l->map[y][x - 1] = 'N';
	else
		l->map[y][x - 1] = 'Y';
	l->map[y][x] = '0';
}
