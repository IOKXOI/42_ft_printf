/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:58:51 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/07 22:44:56 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

static char *ft_getchar(char c, t_struct *data)
{
	char	*formated;

	if (!c)
		data->null_char = 1;
	formated = malloc(2);
	formated[0] = c;
	formated[1] = '\0';
	return (formated);
}

static char	*ft_itoa(int n)
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

static char	*ft_itoa_base(int n, char *base)
{
	int				i;
	unsigned int	save;
	char			*num;
	
	i = 1;
	save = n;
	while (save >= 16 && i++)
		save = save / 16;
	save = n;
	num = malloc(sizeof(char) * (i + 3));
	if (!num)
		return (NULL);
	num[i] = '\0';
	while (i)
	{
		num[--i] = base[(save % 16)];
		save /= 16;
	}
	return (num);
}

static char	*ft_itoa_u(size_t n)
{
	int		i;
	size_t	save;
	char	*num;

	i = 1;
	save = n;
	while (save >= 10 && i++)
		save = save / 10;
	save = n;
	num = malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	num[i] = '\0';
	while (i)
	{
		num[--i] = (save % 10 + '0');
		save /= 10;
	}
	return (num);
}
/*
char *check_ptr(char *num)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (num[i] == '0')
		i++;
	if (i == 3)
	{
		temp = malloc(sizeof(char) * 13);
		i = 2;
		j = 4;
		while (i < 13)
		{
			temp[i] = num[j];
			i++;
			j++;
		}
		free(num);
		return (temp);
	}
	return (num);
}*/

static char	*ft_itoa_base_u(size_t n, char *base)
{
	int				i;
	size_t			save;
	char			*num;
	
	i = 1;
	save = n;
	if (!n)
		return (ft_strdup("(nil)"));
	if (save < 16)
		i += 2;
	while (save >= 16 && i++)
		save = save / 16;
	num = malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	num[i] = '\0';
	while (i > 1)
	{
		num[--i] = base[(n % 16)];
		n /= 16;
	}
	num[0] = '0';
	num[1] = 'x';
	return (num);
}

static char *ft_get_address(void *ptr)
{
	size_t	address;
	char	*formated;

	address = (size_t)ptr;
	formated = ft_itoa_base_u(address, "0123456789abcdef");
	
	return (formated); 
}

char *converter(const char *format, t_struct *data, va_list args)
{
	size_t	i;
	char	*formated;
	
	i = data->form_offset + 1;
	if (format[i] == 'c')
		formated = ft_getchar(va_arg(args, int), data);
	else if (format[i] == 's')
		formated = ft_strdup(va_arg(args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		formated = ft_itoa(va_arg(args, int));
	else if (format[i] == 'u')
		formated = ft_itoa_u(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		formated = ft_itoa_base(va_arg(args, int), "0123456789abcdef");
	else if (format[i] == 'X')
		formated = ft_itoa_base(va_arg(args, int), "0123456789ABCDEF");
	else if (format[i] == 'p')
		formated = ft_get_address(va_arg(args, void*));
	else if (format[i] == '%')
		formated = ft_getchar('%', data);
	else
		formated = (ft_strdup(""));
	data->form_offset = (i + 1);
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

char *ft_itoa(size_t nbr)
{
	size_t		save_nbr;
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
