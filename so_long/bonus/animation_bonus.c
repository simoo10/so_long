/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:56:15 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/28 14:56:18 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(img->mlx, path, &img->width_img,
			&img->heigh_img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->j * 50,
		img->i * 50);
	mlx_destroy_image(img->mlx, img->img);
}

void	animation_img(t_img *img, int *c)
{
	put_img(img, "./bonus/textures/11.xpm");
	if (*c == 1)
		put_img(img, "./bonus/textures/12.xpm");
	else if (*c == 2)
		put_img(img, "./bonus/textures/C11.xpm");
	else if (*c == 3)
		put_img(img, "./bonus/textures/C22.xpm");
	else if (*c == 4)
		put_img(img, "./bonus/textures/C33.xpm");
	else if (*c == 5)
		put_img(img, "./bonus/textures/C44.xpm");
	else if (*c == 6)
		put_img(img, "./bonus/textures/C55.xpm");
}

void	coin_position(t_img *img, int x)
{
	t_pos	pts;

	pts.y = 0;
	while (img->map[pts.y])
	{
		pts.i = 0;
		while (img->map[pts.y][pts.i])
		{
			if (img->map[pts.y][pts.i] == 'C')
			{
				img->j = pts.i;
				img->i = pts.y;
				animation_img(img, &x);
			}
			pts.i++;
		}
		pts.y++;
	}
}

int	animation(t_img *img)
{
	t_pos		pts;
	static int	c;
	static int	x;

	pts.y = 0;
	if (c % 2000 != 0)
		return (c++, 0);
	coin_position(img, x);
	if (x == 6)
		x = 0;
	x++;
	c++;
	ennimy(img, img->monsters);
	return (0);
}
