/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:23:51 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/13 21:23:57 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(char *map)
{
	int		fd;
	char	*line;
	char	*v;
	char	**split;
	int		i;

	split = NULL;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	v = NULL;
	i = 0;
	while (line)
	{
		empty_line(line);
		v = ft_strjoin(v, line);
		free(line);
		line = get_next_line(fd);
	}
	empty_file(v);
	i = ft_strlen(v);
	empty_line2(v[i - 1]);
	split = ft_split(v, '\n');
	free(v);
	close (fd);
	return (split);
}

int	check_rectangular(char **v)
{
	int	i;

	i = 0;
	while (v[i] && v[i + 1])
	{
		if (ft_strlen(v[i]) != ft_strlen(v[i + 1]))
		{
			return (0);
			break ;
		}
		i++;
	}
	return (1);
}

int	check_all(char **v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] != '0' && v[i][j] != '1' && v[i][j] != 'C'
				&& v[i][j] != 'P' && v[i][j] != 'E')
			{
				return (0);
				break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(char **v)
{
	if (check_all(v) == 0)
	{
		ft_putstr("\x1B[31mError\nINVALID MAP STRUCTURE\n");
		exit(1);
	}
	if (check_player(v) != 1)
	{
		ft_putstr("\x1B[31mError\n---INVALID NUMBER OF PLAYER!---\n");
		exit(1);
	}
	if (check_items(v) < 1)
	{
		ft_putstr("\x1B[31mError\n---INVALID NUMBER OF ITEMS!---\n");
		exit(1);
	}
	if (check_exit(v) != 1)
	{
		ft_putstr("\x1B[31mError\n---INVALID NUMBER OF EXITS!---\n");
		exit(1);
	}
}

void	check_map2(char **v)
{
	if (check_wall(v) == 0)
	{
		ft_putstr("\x1B[31mError\n---INVALID MAP FRAMEWORK!---\n");
		exit(1);
	}
	if (check_rectangular(v) == 0)
	{
		ft_putstr("\x1B[31mError\n---INVALID TYPE OF MAP!---\n");
		exit(1);
	}
}
