/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:22:24 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/28 11:22:25 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xpm_error(t_img *img)
{
	if (!img->img)
	{
		ft_putstr("Error\n Oops!SOMETHING happend \n");
		exit(1);
	}
}

void	put_ennemi(t_img *img)
{
	if (img->map[img->i][img->j] == 'V')
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/77.xpm",
				&img->width_img, &img->heigh_img);
		xpm_error(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->j * 50,
			img->i * 50);
		mlx_destroy_image(img->mlx, img->img);
	}
}

int	show_map(t_img *img)
{
	img->i = 0;
	img->j = 0;
	while (img->map[img->i])
	{
		img->j = 0;
		while (img->map[img->i][img->j])
		{
			img->map = put_items(img);
			img->map = put_full(img);
			img->map = put_wall(img);
			img->map = put_player(img);
			img->map = put_exit(img);
			put_ennemi(img);
			img->j++;
		}
		img->i++;
	}
	return (0);
}
