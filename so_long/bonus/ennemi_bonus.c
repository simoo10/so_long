/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:44:49 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/29 18:44:51 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*lst_ennemi(t_list *list, t_img *img)
{
	t_list	*f;
	t_pos	pt;

	list = NULL;
	pt.y = 0;
	while (img->map[pt.y])
	{
		pt.i = 0;
		while (img->map[pt.y][pt.i])
		{
			if (img->map[pt.y][pt.i] == 'V')
			{
				f = lstnews(pt);
				f->ort = 1;
				ft_add_front(&list, f);
			}
			pt.i++;
		}
		pt.y++;
	}
	return (list);
}

void	img_ennimy(t_img *img, t_list *a)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/77.xpm",
			&img->width_img, &img->heigh_img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (a->pt.i - 1)
		* 50, a->pt.y * 50);
	img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/11.xpm",
			&img->width_img, &img->heigh_img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (a->pt.i) * 50,
		a->pt.y * 50);
	mlx_destroy_image(img->mlx, img->img);
	if (img->map[a->pt.y][a->pt.i - 1] == 'P')
		loser();
	img->map[a->pt.y][a->pt.i - 1] = 'V';
	img->map[a->pt.y][a->pt.i] = '0';
	a->pt.i = a->pt.i - 1;
}

void	img_ennimy1(t_img *img, t_list *a)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/77.xpm",
			&img->width_img, &img->heigh_img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (a->pt.i + 1)
		* 50, a->pt.y * 50);
	img->img = mlx_xpm_file_to_image(img->mlx, "./bonus/textures/11.xpm",
			&img->width_img, &img->heigh_img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, (a->pt.i) * 50,
		a->pt.y * 50);
	mlx_destroy_image(img->mlx, img->img);
	if (img->map[a->pt.y][a->pt.i + 1] == 'P')
		loser();
	img->map[a->pt.y][a->pt.i + 1] = 'V';
	img->map[a->pt.y][a->pt.i] = '0';
	a->pt.i = a->pt.i + 1;
}

int	ennimy(t_img *img, t_list *a)
{
	while (a)
	{
		if ((img->map[a->pt.y][a->pt.i - 1] != '1' && img->map[a->pt.y][a->pt.i
			- 1] != 'C' && img->map[a->pt.y][a->pt.i - 1] != 'V'
				&& img->map[a->pt.y][a->pt.i - 1] != 'E') && a->ort == 1)
			img_ennimy(img, a);
		if ((img->map[a->pt.y][a->pt.i + 1] != '1' && img->map[a->pt.y][a->pt.i
			+ 1] != 'C' && img->map[a->pt.y][a->pt.i + 1] != 'V'
				&& img->map[a->pt.y][a->pt.i + 1] != 'E') && a->ort == 0)
			img_ennimy1(img, a);
		if (img->map[a->pt.y][a->pt.i - 1] == '1' || img->map[a->pt.y][a->pt.i
			- 1] == 'C' || img->map[a->pt.y][a->pt.i - 1] == 'E'
			|| img->map[a->pt.y][a->pt.i - 1] == 'V')
			a->ort = 0;
		else if (img->map[a->pt.y][a->pt.i + 1] == '1'
				|| img->map[a->pt.y][a->pt.i + 1] == 'C'
				|| img->map[a->pt.y][a->pt.i + 1] == 'V'
				|| img->map[a->pt.y][a->pt.i + 1] == 'E')
			a->ort = 1;
		a = a->next;
	}
	return (0);
}
