#include "../ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void struct_init(t_struct *my_struct)
{
	my_struct->buff_offset = 0;
	my_struct->form_offset = 0;
	my_struct->wrote = 0;
}


/*int	browse(const char *format, char *buffer, t_struct *data)
{
	size_t	i;
	size_t	j;

	i = data->buff_offset;
	j = data->form_offset;
	while(format[i] || format[i] != '%')
	{
		buffer[j++] = format[i++];
		if (!format[i] || buffer[j - 1] == '\n' || j == 1024)
		{
			data->wrote += write(1, buffer, j);
			if (!format[i])
				return (0);
			j = 0;
		}
	}
	if (j != 0)
		j++;
	data->form_offset = j;
	data->buff_offset = i;
	return (1);
}*/
int browse(const char *format, char *buffer, t_struct *data)
{
	size_t	i;
	size_t	j;

	i = data->buff_offset;
	j = data->form_offset;
	while(format[i] || format[i] != '%')
	{
		buffer[j++] = format[i++];
		if (!format[i] || buffer[j - 1] == '\n' || j == 1024)
		{
			data->wrote += write(1, buffer, j);
			if (!format[i])
				return (0);
			j = 0;
		}
	}
	if (j != 0)
		j++;
	data->form_offset = j;
	data->buff_offset = i;
	return (1);
}

int		ft_printf(const char *format, ...)
{
	char		buffer[1025];
	//va_list 	args;
	t_struct	data;

	if (!format || !*format)
		return (0);
	struct_init(&data);
//	va_start(args, format);
	while (browse(format, buffer, &data))
	{
		printf("ok\n");
	}
//	str = converted(format);
//	va_end(va_args);
	return (data.wrote);
}

int main()
{
	int nb;


	nb = ft_printf("012345678901234567890123456789012345678901\n2");
	//write(1, "OK\n", 3);
	printf("nb = %d", nb);

	//printf("%s", buffer);
	return (nb);
}
