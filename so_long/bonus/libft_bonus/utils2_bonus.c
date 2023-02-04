/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:29:13 by met-tahe          #+#    #+#             */
/*   Updated: 2023/01/31 15:29:15 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*p;
	int		leng;

	leng = numlen(n);
	i = leng - 1;
	p = malloc(leng + 1);
	if (!p)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(p, "-2147483648"));
	if (n < 0)
	{
		n = -n;
		p[0] = '-';
	}
	if (n == 0)
		p[i] = n + 48;
	while (n > 0)
	{
		p[i--] = (n % 10) + 48;
		n = n / 10;
	}
	p[leng] = 0;
	return (p);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		i++;
	}
	write(1, s, i);
}
