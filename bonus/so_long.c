/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:32:51 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/04 16:01:25 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void convert_myfile_toimg(t_list *list)
{
	int x = 65;
	int i;

	i = 0;
	list->Wall =  mlx_xpm_file_to_image(list->mlx, "img/Wall.xpm", &x , &x);
	list->Background =  mlx_xpm_file_to_image(list->mlx, "img/Background.xpm",&x, &x);
	list->Player_move_down =  mlx_xpm_file_to_image(list->mlx, "img/move_down.xpm",&x, &x);
	list->Player_move_left =  mlx_xpm_file_to_image(list->mlx, "img/move_left.xpm",&x, &x);
	list->Player_move_right =  mlx_xpm_file_to_image(list->mlx, "img/move_right.xpm",&x, &x);
	list->Player_move_up =  mlx_xpm_file_to_image(list->mlx, "img/move_up.xpm",&x, &x);
	list->Closed_door =  mlx_xpm_file_to_image(list->mlx, "img/Closed_door.xpm",&x, &x);
	list->Open_door =  mlx_xpm_file_to_image(list->mlx, "img/Open_door.xpm",&x, &x);
	list->Collectible =  mlx_xpm_file_to_image(list->mlx, "img/Collectible.xpm",&x, &x);
	if (!list->Wall || !list->Background || !list->Player_move_down || !list->Player_move_left
	|| !list->Player_move_right || !list->Player_move_up || !list->Closed_door 
	|| !list->Open_door || !list->Collectible)
	{
		write (2, "Error\ncan't convert .xpm to image \n", 36);
		while (list->map[i] != NULL)
			free(list->map[i++]);
		free(list->map);
		exit (1);
	}
}

int key_press(int key_code, t_list *l)
{
	l->j = l->i;
	if (key_code == 65362)
		ft_move_up(l);
	else if (key_code == 65363)
		ft_move_right(l);
	else if (key_code == 65364)
		ft_move_down(l);
	else if (key_code == 65361)
		ft_move_left(l);
	else if (key_code == 65307)
		end_game(l, 1);
	if (l->j != l->i)
	{
		write (1, "move : ", 8);
		ft_putnbr(l->i);
		write (1, "\n", 1);	
		l->move = ft_itoa(l->i);
		mlx_put_image_to_window(l->mlx, l->win, l->Wall, 0, 0);
		mlx_put_image_to_window(l->mlx, l->win, l->Wall, 50, 0);
		mlx_string_put(l->mlx, l->win, 0, 0, 0x00000A, "Move Num : ");
		mlx_put_image_to_window(l->mlx, l->win, l->Wall, 100, 0);
		mlx_string_put(l->mlx, l->win, 100, 0, 0x000000, l->move);
		free (l->move);
	}
	return(0);
}

int destroy(t_list *list)
{
	free_map(list);
	exit(0);
}

void f()
{
	system("leaks so_long");
}



void	so_long(t_list *list)
{
	list->mlx = mlx_init();
	if (list->size_x > 40 || list->size_y > 22)
	{
		write (2, "Error\nImage dimensions are not correct\n", 40);
		free_map(list);
		exit(1);
	}
	list->win = mlx_new_window(list->mlx, list->size_x * 65, list->size_y * 65, "so_long");
	convert_myfile_toimg(list);
	mlx_hook(list->win, 17,0, destroy, list);
	put_images_towin(list);
	list->i = 0;
	mlx_hook(list->win, 2, 1L<<0, &key_press, list);
	list->En_move_nb = 0;
	if (list->En_count != 0)
		put_enemy_towin(list);
	mlx_loop_hook(list->mlx, &ft_handel_enemy, list);
	mlx_loop(list->mlx);
}

int main(int arc, char **arv)
{
	int fd;
	t_list list;
	//atexit(f);
	if (arc == 2)
	{
		if (ft_ending_by_ber(arv[1]) == 0)
		{
			write (2, "Error\nmap name not correct\n", 28);
			exit (1);
		}
		fd = open(arv[1], O_RDWR, 0777);
		if (fd < 0)
		{
			write (2, "Error\ncan't open map file\n", 27);
			exit (1);
		}
		parsing(&list, fd);
		get_c_num_e_pos(&list);
		so_long(&list);
	}
	else
	{
		write (2, "Error\nnumber of arg not correct\n", 33);
		exit (1);
	}
}
