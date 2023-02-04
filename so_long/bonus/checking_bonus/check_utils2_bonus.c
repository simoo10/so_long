/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:57 by met-tahe          #+#    #+#             */
/*   Updated: 2023/02/02 15:12:59 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

void	flood_fill2(int x, int y, char **map, char f)
{
	if (map[x][y] != '1' && map[x][y] != 'V' && map[x][y] != f)
		map[x][y] = f;
	else
		return ;
	flood_fill2(x + 1, y, map, f);
	flood_fill2(x - 1, y, map, f);
	flood_fill2(x, y + 1, map, f);
	flood_fill2(x, y - 1, map, f);
}

int	check_path2(char **map)
{
	int	i;
	int	y;

	y = 0;
	while (map[y])
	{
		i = 0;
		while (map[y][i])
		{
			if (map[y][i] == 'P')
				break ;
			i++;
		}
		if (map[y][i] == 'P')
			break ;
		y++;
	}
	flood_fill2(y, i, map, 'f');
	y = 0;
	i = 0;
	exit_path(map, y, i);
	return (0);
}

void	exit_path(char **map, int y, int i)
{
	while (map[y])
	{
		i = 0;
		while (map[y][i])
		{
			if (map[y][i] == 'E')
			{
				ft_putstr("\x1B[31mError\n---INVALID PATH---\n");
				exit(0);
			}
			i++;
		}
		y++;
	}
	return ;
}
