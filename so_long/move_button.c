/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:09:38 by met-tahe          #+#    #+#             */
/*   Updated: 2023/02/01 19:09:42 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	img->map[*y][*i] = 'O';
	img->map[*y][*i + 1] = 'P';
	img_d(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
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
		{
			win_exit(counter, img->count);
		}
	}
	img->map[*y][*i] = 'O';
	img->map[*y - 1][*i] = 'P';
	img_w(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
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
	img->map[*y][*i] = 'O';
	img->map[*y][*i - 1] = 'P';
	img_a(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
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
		{
			win_exit(counter, img->count);
		}
	}
	img->map[*y][*i] = 'O';
	img->map[*y + 1][*i] = 'P';
	img_s(img, i, y);
	img->count++;
	counter = ft_itoa(img->count);
	ft_putstr(counter);
	free(counter);
	ft_putstr("\n");
}
