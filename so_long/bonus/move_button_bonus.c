/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_button_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:47:09 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 15:47:12 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wall_count(t_img *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/mur1.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);
}

void	d(t_img *img, int *i, int *y)
{
	char	*counter;

	counter = NULL;
	if (img->map[*y][*i + 1] == '1')
		return ;
	if (img->map[*y][*i + 1] == 'E')
	{
		img->count++;
		if (items_count(img) == 1)
			return ;
		else
			win_exit(counter, img->count);
	}
	if (img->map[*y][*i + 1] == 'V')
		loser();
	img->map[*y][*i] = 'O';
	img->map[*y][*i + 1] = 'P';
	img_d(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
	wall_count(img);
	mlx_string_put(img->mlx, img->mlx_win, 15, 15, 00000000, counter);
	ft_putstr(counter);
	free(counter);
	ft_putstr("\n");
}

void	w(t_img *img, int *i, int *y)
{
	char	*counter;

	counter = NULL;
	if (img->map[*y - 1][*i] == '1')
		return ;
	if (img->map[*y - 1][*i] == 'E')
	{
		img->count++;
		if (items_count(img) == 1)
			return ;
		else
			win_exit(counter, img->count);
	}
	if (img->map[*y - 1][*i] == 'V')
		loser();
	img->map[*y][*i] = 'O';
	img->map[*y - 1][*i] = 'P';
	img_w(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
	wall_count(img);
	mlx_string_put(img->mlx, img->mlx_win, 15, 15, 00000000, counter);
	ft_putstr(counter);
	free(counter);
	ft_putstr("\n");
}

void	a(t_img *img, int *i, int *y)
{
	char	*counter;

	counter = NULL;
	if (img->map[*y][*i - 1] == '1')
		return ;
	if (img->map[*y][*i - 1] == 'E')
	{
		img->count++;
		if (items_count(img) == 1)
			return ;
		else
			win_exit(counter, img->count);
	}
	if (img->map[*y][*i - 1] == 'V')
		loser();
	img->map[*y][*i] = 'O';
	img->map[*y][*i - 1] = 'P';
	img_a(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
	wall_count(img);
	mlx_string_put(img->mlx, img->mlx_win, 15, 15, 00000000, counter);
	ft_putstr(counter);
	free(counter);
	ft_putstr("\n");
}

void	s(t_img *img, int *i, int *y)
{
	char	*counter;

	counter = NULL;
	if (img->map[*y + 1][*i] == '1')
		return ;
	if (img->map[*y + 1][*i] == 'E')
	{
		img->count++;
		if (items_count(img) == 1)
			return ;
		else
			win_exit(counter, img->count);
	}
	if (img->map[*y + 1][*i] == 'V')
		loser();
	img->map[*y][*i] = 'O';
	img->map[*y + 1][*i] = 'P';
	img_s(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
	wall_count(img);
	mlx_string_put(img->mlx, img->mlx_win, 15, 15, 00000000, counter);
	ft_putstr(counter);
	free(counter);
	ft_putstr("\n");
}
