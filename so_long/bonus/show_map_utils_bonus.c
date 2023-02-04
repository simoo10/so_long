/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:01:51 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 19:01:53 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**put_items(t_img *img)
{
	if (img->map[img->i][img->j] == 'C')
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/12.xpm",
				&img->width_img, &img->heigh_img);
		xpm_error(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->j * 50,
			img->i * 50);
		mlx_destroy_image(img->mlx, img->img);
	}
	return (img->map);
}

char	**put_wall(t_img *img)
{
	if (img->map[img->i][img->j] == '1')
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/mur1.xpm",
				&img->width_img, &img->heigh_img);
		xpm_error(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (img->j) * 50,
			(img->i) * 50);
		mlx_destroy_image(img->mlx, img->img);
	}
	return (img->map);
}

char	**put_full(t_img *img)
{
	if (img->map[img->i][img->j] == '0')
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/11.xpm",
				&img->width_img, &img->heigh_img);
		xpm_error(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (img->j) * 50,
			(img->i) * 50);
		mlx_destroy_image(img->mlx, img->img);
	}
	return (img->map);
}

char	**put_player(t_img *img)
{
	if (img->map[img->i][img->j] == 'P')
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/pp.xpm",
				&img->width_img, &img->heigh_img);
		xpm_error(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->j * 50,
			img->i * 50);
		mlx_destroy_image(img->mlx, img->img);
	}
	return (img->map);
}

char	**put_exit(t_img *img)
{
	if (img->map[img->i][img->j] == 'E')
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/15.xpm",
				&img->width_img, &img->heigh_img);
		xpm_error(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->j * 50,
			img->i * 50);
		mlx_destroy_image(img->mlx, img->img);
	}
	return (img->map);
}
