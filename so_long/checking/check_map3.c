/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:15:12 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 12:15:14 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_player(char **v)
{
	int	i;
	int	j;
	int	np;

	np = 0;
	i = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] == 'P')
				np++;
			j++;
		}
		i++;
	}
	return (np);
}

int	check_items(char **v)
{
	int	i;
	int	j;
	int	ni;

	i = 0;
	ni = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] == 'C')
				ni++;
			j++;
		}
		i++;
	}
	return (ni);
}

int	check_exit(char **v)
{
	int	i;
	int	j;
	int	ne;

	i = 0;
	ne = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] == 'E')
				ne++;
			j++;
		}
		i++;
	}
	return (ne);
}

void	flood_fill(int x, int y, char **map, char f)
{
	if (map[x][y] != '1' && map[x][y] != 'E' && map[x][y] != f)
		map[x][y] = f;
	else
		return ;
	flood_fill(x + 1, y, map, f);
	flood_fill(x - 1, y, map, f);
	flood_fill(x, y + 1, map, f);
	flood_fill(x, y - 1, map, f);
}
