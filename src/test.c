#include "../inc/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	nb;
	char *str = "Hello world how long is this string? It must be pretty long!";

	nb = ft_strlen(str);
	ft_printf("My ft_printf: Here is an int: \t\t%d\n", nb);
	printf("stdio.h printf: Here is an int: \t%d\n", nb);
	ft_printf("My ft_printf: Here is a char: \t\t%c\n", *str);
	printf("stdio.h printf: Here is a char: \t%d\n", *str);
	return (0);
}
