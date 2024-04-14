/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:57:54 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/04/04 02:40:03 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <mlx.h>
# include "mlx_int.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char	**map;
	char	*move;
	int 	i;
	int 	j;
	int 	size_x;
	int 	size_y;
	int		En_count;
	int		En_move_nb;
	void 	*mlx;
	void 	*win;
	void	*Player;
	void	*Player_move_down;
	void	*Player_move_left;
	void	*Player_move_right;
	void	*Player_move_up;
	void	*En_mu;
	void	*En_ml;
	void	*En_mr;
	void	*En_md;
	void	*Open_door;
	void	*Closed_door;
	void	*Collectible;
	void	*Wall;
	void	*Background;
	char	**map_copy;
	int		p_y;
	int		p_x;
	int		e_x;
	int		e_y;
	int		c_count;
}	t_list;

void	cheack_with_flood_fill(t_list *lst, int c_countr, int t_countr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_ending_by_ber(char *map_name);
size_t	ft_strlen(const char	*str);
int		ft_find_newline(char	*str);
char	**freeword(char **str, size_t idx);
char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	parsing(t_list	*list, int fd);
void	cheack_all_len(t_list *list);
char	**creat_map_copy(char **map);
void	find_error1(t_list *list, int i);
void	find_error(char *str, char *s, int i);
char	*get_next_line(int fd);
void	free_map(t_list *list);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
void	put_images_towin(t_list *list);
void	ft_putnbr(int n);
void	end_game(t_list *l,int i);
void	get_c_num_e_pos(t_list *l);
void	ft_move_left(t_list *l);
void	ft_move_down(t_list *l);
void	ft_move_right(t_list *l);
void	ft_move_up(t_list *l);
void	ft_enemy_move_right(t_list *l, int x, int y);
void	ft_enemy_move_left(t_list *l, int x, int y);
void	ft_enemy_move_down(t_list *l, int x, int y);
void	ft_enemy_move_up(t_list *l, int x, int y);
void	put_enemy_towin(t_list *list);
void	convert_myenemy_img(t_list *list);
void	ft_enemy_move(t_list *list);
int 	ft_handel_enemy(t_list *list);
char	*ft_itoa(int i);

#endif