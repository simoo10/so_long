/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:57 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 15:31:01 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	first_line(char **v, int i, int j)
{
	while (v[i][j])
	{
		if (v[i][j] != '1')
		{
			return (0);
			break ;
		}
		j++;
	}
	return (1);
}

int	last_line(char **v, int i, int j)
{
	while (v[i][j])
	{
		if (v[i][j] != '1')
		{
			return (0);
			break ;
		}
		j++;
	}
	return (1);
}

int	check_wall(char **v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (first_line(v, i, j) == 0)
		return (0);
	while (v[i])
	{
		if (v[i][0] != '1' || v[i][ft_strlen(v[i]) - 1] != '1')
		{
			return (0);
			break ;
		}
		i++;
	}
	i--;
	j = 0;
	if (last_line(v, i, j) == 0)
		return (0);
	return (1);
}

void	coin_path(char **map, int y, int i)
{
	while (map[y])
	{
		i = 0;
		while (map[y][i])
		{
			if (map[y][i] == 'C')
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

int	check_path(char **map)
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
	flood_fill(y, i, map, 'f');
	y = 0;
	i = 0;
	coin_path(map, y, i);
	return (0);
}
