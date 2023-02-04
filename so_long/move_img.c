/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:30:35 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 12:30:37 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_w(t_img *img, int *i, int *y)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/pp.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i) * 50, (*y
			- 1) * 50);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/11.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i) * 50, (*y)
		* 50);
	mlx_destroy_image(img->mlx, img->img);
}

void	img_s(t_img *img, int *i, int *y)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/pp.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i) * 50, (*y
			+ 1) * 50);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/11.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i) * 50, (*y)
		* 50);
	mlx_destroy_image(img->mlx, img->img);
}

void	img_a(t_img *img, int *i, int *y)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/pp1.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i - 1) * 50,
		(*y) * 50);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/11.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i) * 50, (*y)
		* 50);
	mlx_destroy_image(img->mlx, img->img);
}

void	img_d(t_img *img, int *i, int *y)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/pp.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i + 1) * 50,
		(*y) * 50);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_xpm_file_to_image(img->mlx, "./textures/11.xpm",
			&img->width_img, &img->heigh_img);
	xpm_error(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (*i) * 50, (*y)
		* 50);
	mlx_destroy_image(img->mlx, img->img);
}

void	winner(void)
{
	ft_putstr("YOU WIN\n");
	exit(0);
}
