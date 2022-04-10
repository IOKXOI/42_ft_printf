/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:25:05 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/10 07:58:55 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "converter.c"
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

	while(format[i] && format[i] != '%')
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
	if (!format[i])
	{
		data->wrote = write(1, buffer, j);
		return (0);
	}
	return (1);
}

static void formated_to_buffer(char *str_formated, char *buffer, t_struct *data)
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
//	data.wrote = write(1, buffer, data.buff_offset);
	va_end(args);
	return (data.wrote);
}
/*
int main()
{
//	char * formated;
	int nb = 100;
	unsigned u_nb = nb;
	int my_return;
	int el_return; 
	
	my_return = ft_printf("%u %p", u_nb, &u_nb);
	el_return = printf("%u %p", u_nb, &u_nb);
	printf("\nmy_return = %d",my_return);
	printf("\nel_return = %d",el_return);
//	ft_printf("bonjour le %u", nb);
	//printf("\n%%%%\n");
	//formated = ft_itoa_base(42, "0123456789ABCDEF");
//	printf("%s", formated);
	return (0);
}
*/
