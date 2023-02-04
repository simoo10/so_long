/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:22:35 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/28 11:22:40 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_pos
{
	int				i;
	int				y;
}					t_pos;
typedef struct s_list
{
	t_pos			pt;
	int				ort;
	struct s_list	*next;
}					t_list;

typedef struct s_img
{
	int				width_img;
	int				heigh_img;
	char			**map;
	int				x_map;
	int				y_map;
	void			*img;
	void			*mlx;
	void			*mlx_win;
	char			*path;
	int				i;
	int				j;
	int				e;
	int				count;
	t_list			*monsters;
	t_list			*first_monster;
}					t_img;

char				*ft_read_fd(int fd, char *s);
char				*get_next_line(int fd);
char				*ft_reste(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *s, int c);
char				*ft_get_line(char *s);
size_t				ft_strlen(char *c);
int					check_player(char **v);
void				ft_putstr(char *s);
int					check_item(char *map);
char				**ft_split(char const *s, char c);
int					check_rectangular(char **v);
void				check_map(char **v);
int					check_player(char **v);
int					check_all(char **v);
int					check_wall(char **v);
int					check_exit(char **v);
int					check_items(char **v);
int					check_path(char **map);
char				**read_map(char *map);
void				flood_fill(int x, int y, char **map, char f);
int					move_player(int code, t_img *img);
void				s(t_img *img, int *i, int *y);
void				d(t_img *img, int *i, int *y);
void				w(t_img *img, int *i, int *y);
void				a(t_img *img, int *i, int *y);
int					items_count(t_img *map);
char				*ft_itoa(int n);
char				**put_items(t_img *img);
char				**put_wall(t_img *img);
char				**put_full(t_img *img);
char				**put_player(t_img *img);
char				**put_exit(t_img *img);
int					show_map(t_img *img);
t_pos				player_position(t_img *img, t_pos x);
char				**read_map(char *map);
int					animation(t_img *img);
void				animation_img(t_img *img, int *c);
void				put_img(t_img *img, char *path);
void				img_w(t_img *img, int *i, int *y);
void				img_d(t_img *img, int *i, int *y);
void				img_a(t_img *img, int *i, int *y);
void				img_s(t_img *img, int *i, int *y);
t_list				*lst_ennemi(t_list *list, t_img *img);
int					ennimy(t_img *img, t_list *a);
void				img_ennimy(t_img *img, t_list *a);
int					check_ennimy(char **v);
void				img_ennimy1(t_img *img, t_list *a);
void				winner(void);
void				loser(void);
t_list				*lstnews(t_pos content);
void				ft_add_front(t_list **lst, t_list *new);
void				xpm_error(t_img *img);
void				empty_line2(char v);
void				empty_line(char *line);
void				empty_file(char *v);
void				check_map2(char **v);
void				win_exit(char *counter, int count);
void				arg_invalid(void);
void				arg_check(char *v, int c);
void				flood_fill2(int x, int y, char **map, char f);
int					check_path2(char **map);
void				exit_path(char **map, int y, int i);
void				path(char *v);

#endif
