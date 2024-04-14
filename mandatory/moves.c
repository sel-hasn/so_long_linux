/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:30:42 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/04 16:00:10 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_list *l)
{
	if (l->map[l->p_y - 1][l->p_x] == 'C')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_up, l->p_x * 65, (l->p_y - 1) * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y - 1][l->p_x] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->p_y--;
		l->i++;
		l->c_count--;
	}
	else if (l->map[l->p_y - 1][l->p_x] == '0')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_up, l->p_x * 65, (l->p_y - 1) * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y - 1][l->p_x] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->i++;
		l->p_y--;
	}
	else if (l->map[l->p_y - 1][l->p_x] == '1' || (l->map[l->p_y - 1][l->p_x] == 'E' && l->c_count != 0))
		return ;
	else if (l->map[l->p_y - 1][l->p_x] == 'E' && l->c_count == 0)
		end_game(l, 0);
	if (l->c_count == 0)
		mlx_put_image_to_window(l->mlx, l->win, l->Open_door, l->e_x * 65, l->e_y * 65);
}

void	ft_move_right(t_list *l)
{
	if (l->map[l->p_y][l->p_x + 1] == 'C')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_right, (l->p_x + 1) * 65, l->p_y * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y][l->p_x + 1] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->p_x++;
		l->i++;
		l->c_count--;
	}
	else if (l->map[l->p_y][l->p_x + 1] == '0')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_right, (l->p_x + 1) * 65, l->p_y * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y][l->p_x + 1] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->i++;
		l->p_x++;
	}
	else if (l->map[l->p_y][l->p_x + 1] == '1' || (l->map[l->p_y][l->p_x + 1] == 'E' && l->c_count != 0))
		return ;
	else if (l->map[l->p_y][l->p_x + 1] == 'E' && l->c_count == 0)
		end_game(l, 0);
	if (l->c_count == 0)
		mlx_put_image_to_window(l->mlx, l->win, l->Open_door, l->e_x * 65, l->e_y * 65);
}

void	ft_move_down(t_list *l)
{
	if (l->map[l->p_y + 1][l->p_x] == 'C')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_down, l->p_x * 65, (l->p_y + 1) * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y + 1][l->p_x] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->p_y++;
		l->i++;
		l->c_count--;
	}
	else if (l->map[l->p_y + 1][l->p_x] == '0')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_down, l->p_x * 65, (l->p_y + 1) * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y + 1][l->p_x] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->i++;
		l->p_y++;
	}
	else if (l->map[l->p_y + 1][l->p_x] == '1' || (l->map[l->p_y + 1][l->p_x] == 'E' && l->c_count != 0))
		return ;
	else if (l->map[l->p_y + 1][l->p_x] == 'E' && l->c_count == 0)
		end_game(l, 0);
	if (l->c_count == 0)
		mlx_put_image_to_window(l->mlx, l->win, l->Open_door, l->e_x * 65, l->e_y * 65);
}

void	ft_move_left(t_list *l)
{
	if (l->map[l->p_y][l->p_x - 1] == 'C')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_left, (l->p_x - 1) * 65, l->p_y * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y][l->p_x - 1] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->p_x--;
		l->i++;
		l->c_count--;
	}
	else if (l->map[l->p_y][l->p_x - 1] == '0')
	{
		mlx_put_image_to_window(l->mlx, l->win, l->Player_move_left, (l->p_x - 1) * 65, l->p_y * 65);
		mlx_put_image_to_window(l->mlx, l->win, l->Background, l->p_x * 65, l->p_y * 65);
		l->map[l->p_y][l->p_x - 1] = 'P';
		l->map[l->p_y][l->p_x] = '0';
		l->i++;
		l->p_x--;
	}
	else if (l->map[l->p_y][l->p_x - 1] == '1' || (l->map[l->p_y][l->p_x - 1] == 'E' && l->c_count != 0))
		return ;
	else if (l->map[l->p_y][l->p_x - 1] == 'E' && l->c_count == 0)
		end_game(l, 0);
	if (l->c_count == 0)
		mlx_put_image_to_window(l->mlx, l->win, l->Open_door, l->e_x * 65, l->e_y * 65);
}
