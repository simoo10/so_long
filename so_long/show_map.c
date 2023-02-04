/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:58:09 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/16 13:58:12 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_error(t_img *img)
{
	if (!img->img)
	{
		ft_putstr("Error\nOops!somthing hapend\n");
		exit(1);
	}
}

char	**show_map(t_img *img)
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
			img->j++;
		}
		img->i++;
	}
	return (img->map);
}
