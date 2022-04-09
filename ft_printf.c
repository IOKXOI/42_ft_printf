/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:25:05 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/09 07:23:03 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static void struct_init(t_struct *my_struct)
{
	my_struct->buff_offset = 0;
	my_struct->form_offset = 0;
	my_struct->wrote = 0;
}

static int browse(const char *format, char *buffer, t_struct *data)
{
	size_t	i;
	size_t	j;

	i = data->form_offset;
	j = data->buff_offset;
	if (!format[i])
	{
		data->wrote = write(1, buffer, j);
		return (0);
	}
	while(format[i] != '%')
	{
		buffer[j++] = format[i++];
		if (!format[i] || buffer[j - 1] == '\n' || j == 1025)
		{
			data->wrote += write(1, buffer, j);
			if (!format[i])
				return (0);
			j = 0;
		}
	}
	data->buff_offset = j;
	data->form_offset = i;
	return (1);
}

static char *converter(const char *format, t_struct *data, va_list args)
{
	size_t	i;
	char	*formated;
	
	i = data->form_offset + 1;
	if (format[i] == 'c')
		formated = ft_getchar(va_arg(args, int));
	else if (format[i] == 's')
		formated = ft_strcpy(va_arg(args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		formated = ft_itoa(va_arg(args, int));
	else if (format[i] == 'x')
		formated = ft_itoa_base(va_arg(args, int), "0123456789abcdef");
	else if (format[i] == 'X')
		formated = ft_itoa_base(va_arg(args, int), "0123456789ABCDEF");
	else if (format[i] == 'p')
		formated = ft_get_address(va_arg(args, void*));
	else if (format[i] == '%')
		formated = ft_getchar('%');
	data->form_offset = (i + 1);
	return (formated);
}

void formated_to_buffer(char *str_formated, char *buffer, t_struct *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = data->buff_offset;
	while (str_formated[i])
	{
		buffer[j] = str_formated[i];
		j++;
		i++;
		if (j == 1023)
		{
			data->wrote += write(1, buffer, 1024);
			j = 0;
		}
	}
	data->buff_offset = j;
	return;
}

int		ft_printf(const char *format, ...)
{
	char		*str_formated;
	char		buffer[1025];
	va_list 	args;
	t_struct	data;

	if (!format)
		return (0);
	struct_init(&data);
	va_start(args, format);
	while (browse(format, buffer, &data))
	{
		str_formated = converter(format, &data, args);
		if(!str_formated)
			return (-1);
		formated_to_buffer(str_formated, buffer, &data);
		free(str_formated);
	}
	va_end(args);
	return (data.wrote);
}

int main()
{
//	char * formated;
//	int nb = 100;
	int ecole = 15;
	ft_printf("Bonjour comment ca va le %p\n",&ecole);
	printf("\n%p", &ecole);
	//formated = ft_itoa_base(42, "0123456789ABCDEF");
//	printf("%s", formated);
	return (0);
}
