/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:22:03 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/28 11:22:06 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	items_count(t_img *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	size_x(t_img img)
{
	while (img.map[img.i])
		img.i++;
	return (img.i);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	path(char *v)
{
	char	**tmp;

	tmp = read_map(v);
	check_path(tmp);
	ft_free(tmp);
	tmp = read_map(v);
	check_path2(tmp);
	ft_free(tmp);
}

int	main(int c, char **v)
{
	t_img	img;
	t_list	*a;

	img.heigh_img = 50;
	img.width_img = 50;
	img.map = NULL;
	arg_check(v[1], c);
	img.map = read_map(v[1]);
	check_map(img.map);
	check_map2(img.map);
	path(v[1]);
	img.y_map = (ft_strlen(img.map[0])) * 50;
	img.x_map = (size_x(img)) * 50;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.y_map, img.x_map, "SO_LONG");
	show_map(&img);
	a = lst_ennemi(img.monsters, &img);
	img.monsters = a;
	mlx_loop_hook(img.mlx, animation, &img);
	mlx_hook(img.mlx_win, 2, 0, move_player, &img);
	mlx_hook(img.mlx_win, 17, 0, (void *)exit, &img);
	mlx_loop(img.mlx);
}
