#include "../ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



int main()
{
	t_struct t_datas;

	struct_init(&t_datas);
	printf("%ld", t_datas.buff_offset);
	return 0;
}
