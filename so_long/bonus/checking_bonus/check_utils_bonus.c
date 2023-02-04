/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:06:37 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 19:06:39 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	empty_file(char *v)
{
	if (v == NULL)
	{
		ft_putstr("Error\n Oops!SOMETHING happend \n");
		exit(1);
	}
}

void	empty_line(char *line)
{
	if (line[0] == '\n')
	{
		ft_putstr("\x1B[31mError\n---MAP HAVE EMPTY LINE---\n");
		exit(1);
	}
}

void	empty_line2(char v)
{
	if (v == '\n')
	{
		ft_putstr("\x1B[31mError\n---MAP HAVE EMPTY LINE---\n");
		exit(1);
	}
}

void	arg_invalid(void)
{
	ft_putstr("\x1B[31mError\n---INVALID ARGUMENTS---\n");
	exit(1);
}

void	arg_check(char *v, int c)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (c != 2)
		arg_invalid();
	s = ".ber";
	i = ft_strlen(v) - 4;
	while (s[j] && v[i])
	{
		if (s[j] != v[i])
			arg_invalid();
		i++;
		j++;
	}
}
