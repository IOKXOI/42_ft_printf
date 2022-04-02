/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:05:16 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/02 07:51:32 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list 	*args;
	size_t		i;
	va_start(args, str);
	
while (str && *(str + i))
{
	while (*(str + i) != '%')
		i++;
	if (*(str + i + 1) == 'c')
		va_arg(args, char);
	if (*(str + i + 1) == 's')
		va_arg(args, char *);
	if (*(str + i + 1) == 'p')
		va_arg(args, void *);
	if (*(str + i + 1) == 'd' || *(str + i + 1) == 'i')
		va_arg(args, int);
	if (*(str + i + 1) == 'u')
		va_arg(args, unsigned int);
	if (*(str + i + 1) == 'x' || *(str + i + 1) == 'X')
		va_arg(args, unsigned int);
	if (*(str + i + 1) == '%')
}
	va_end(args);
}


