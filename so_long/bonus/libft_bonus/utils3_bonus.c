/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:32:45 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 15:32:47 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_list	*lstnews(t_pos content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (0);
	a->pt = content;
	a->next = 0;
	return (a);
}

void	ft_add_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
