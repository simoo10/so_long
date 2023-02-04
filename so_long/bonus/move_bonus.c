/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:22:14 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/28 11:22:17 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	loser(void)
{
	ft_putstr("\x1B[32mYOU LOSE\n");
	exit(0);
}

void	win_exit(char *counter, int count)
{
	counter = ft_itoa(count);
	ft_putstr(counter);
	free(counter);
	ft_putstr("\n");
	winner();
}

t_pos	player_position(t_img *img, t_pos x)
{
	x.y = 0;
	while (img->map[x.y])
	{
		x.i = 0;
		while (img->map[x.y][x.i])
		{
			if (img->map[x.y][x.i] == 'P')
				break ;
			x.i++;
		}
		if (img->map[x.y][x.i] == 'P')
			break ;
		x.y++;
	}
	return (x);
}

int	move_player(int code, t_img *img)
{
	int			z;
	static int	count;
	t_pos		x;

	z = 0;
	x.y = 0;
	x.i = 0;
	x = player_position(img, x);
	if (code == 53)
		exit(0);
	if (code == 2)
		d(img, &x.i, &x.y);
	if (code == 1)
		s(img, &x.i, &x.y);
	if (code == 0)
		a(img, &x.i, &x.y);
	if (code == 13)
		w(img, &x.i, &x.y);
	return (count);
}
