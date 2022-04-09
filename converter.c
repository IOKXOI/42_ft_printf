/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:58:51 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/09 07:23:18 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_getchar(char c)
{
	char	*formated;

	formated = malloc(2);
	formated[0] = c;
	formated[1] = '\0';
	return (formated);
}

char *ft_strcpy(char *src)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	int				i;
	int				sign;
	unsigned int	save;
	char			*num;

	i = 1;
	sign = 1;
	if (n < 0 && i++)
		sign = -1;
	save = n * sign;
	while (save >= 10 && i++)
		save = save / 10;
	save = n * sign;
	num = malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	num[i] = '\0';
	while (i)
	{
		num[--i] = (save % 10 + '0');
		save /= 10;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}

char	*ft_itoa_base(int n, char *base)
{
	int				i;
	int				sign;
	unsigned int	save;
	char			*num;
	
	i = 1;
	sign = 1;
	if (n < 0 && i++)
		sign = -1;
	save = n * sign;
	while (save >= 10 && i++)
		save = save / 10;
	save = n * sign;
	num = malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	num[i] = '\0';
	while (i)
	{
		num[--i] = base[(save % 16)];
		save /= 16;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}

char *ft_get_address(void *ptr)
{
	size_t	address;
	char	*formated;

	address = (size_t)ptr;
	formated = ft_itoa_base(address, "0123456789abcdef");
	
	return (formated); 
}

/*
static int how_many_number(int nbr)
{
	int				p;
	unsigned int	u_nbr;

	p = 1;
	u_nbr = nbr;
	if (nbr < 0)
	{
		u_nbr = nbr * -1;
		p++;
	}
	while (u_nbr > 9)
	{
		u_nbr /= 10;
		p++;
	}
	return (p);
}

char *ft_itoa(int nbr)
{
	unsigned int save_nbr;
	char		*formated;
	ssize_t		p;

	p = how_many_number(nbr);
	if (nbr < 0)
		save_nbr = nbr * -1;
	else 
		save_nbr = nbr;
	formated = malloc(sizeof(int) * (p + 1));
	if (!formated)
		return (NULL);
	formated[p] = '\0';
	while (p-- >= 0)
	{
		formated[p] = ((save_nbr % 10) + 48);
		save_nbr /= 10;
	}
	if (nbr < 0)
		formated[0] = '-';
	return (formated);
}
*/

