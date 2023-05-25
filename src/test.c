#include "../inc/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char *argv[])
{
	int	nb;
	int	ret;	
	char *str;

	if (argc < 2)
		return (1);
	str = argv[1];
	nb = ft_strlen(str);	
	ret = ft_printf("My ft_printf: Here is an int: \t\t%d\n", INT_MIN);
	printf("Return value: \t\t\t%d\n", ret);
	ret = printf("stdio printf: Here is an int: \t\t%d\n", INT_MIN);
	printf("Return value: \t\t\t%d\n", ret);
	ft_printf("My ft_printf: Here is a char: \t\t%c\n", *str);
	printf("stdio.h printf: Here is a char: \t%d\n", *str);
	printf("%d to the power of %d is: \t\t%lu\n", nb, argc, ft_power(nb, argc));
	printf("The logorithm base 2 of %d is: \t\t%d\n", nb, ft_log(2, nb));
	return (0);
}
