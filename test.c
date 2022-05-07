#include <stdio.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	main(void)
{
	//printf(" %c %c %c ", '0', 0, '1');
	ft_putchar(1);
	return (0);
}
