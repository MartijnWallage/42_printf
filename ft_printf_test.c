/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:35:33 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/27 20:27:24 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>
#include <math.h>

#define TOSTRING(x) #x
#define assert(condition) \
	if (condition)\
		printf("\033[0;32mAssertion succeeded: line %d\033[0m\n", __LINE__);\
	else\
		printf("\033[0;31mAssertion failed: %s, line %d\033[0m\n", TOSTRING(condition),__LINE__);

void	test_utils(void)
{
	int	i, nb;

	for (i = INT_MIN; i < 0; i /= 10)
		assert((int) ft_abs(i) == abs(i));
	assert(is_in_set('a', "Hallo"));
	assert(is_in_set('#', "+-#%x"));
	assert(!is_in_set('d', "#-'0+ "));
}

void	test_conversions(void)
{
	int				ft_ret;
	int				stdio_ret;
	char			*str;
	unsigned int	uns;

	str = "Hello world!";

	ft_ret = ft_printf("1. ft: Here is a char: %c\n", '&');
	stdio_ret = printf("1. st: Here is a char: %c\n", '&');
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("2. ft: Here is a str: %s\n", str);
	stdio_ret = printf("2. st: Here is a str: %s\n", str);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("3. ft: Here is an int: %i\n", 0);
	stdio_ret = printf("3. st: Here is an int: %i\n", 0);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("3.1 ft: Here is another int: %i\n", INT_MAX);
	stdio_ret = printf("3.1 st: Here is another int: %i\n", INT_MAX);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("4. ft: Here is a dec: %d\n", INT_MIN);
	stdio_ret = printf("4. st: Here is a dec: %d\n", INT_MIN);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("5. ft: Here is a pointer: %p\n", str);
	stdio_ret = printf("5. st: Here is a pointer: %p\n", str);
	assert(ft_ret == stdio_ret);

	assert(ft_printf("5.1 ft: %p\n", (void *)-1)
	== printf("5.1 st: %p\n", (void *)-1));

	assert(ft_printf("5.2 ft: %p\n", (void *)-42)
	== printf("5.2 st: %p\n", (void *)-42));

	ft_ret = ft_printf("6. ft: Here is a hex: %x\n", 0x3b24);
	stdio_ret = printf("6. st: Here is a hex: %x\n", 0x3b24);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("7. ft: Here is a hex: %x\n", -42);
	stdio_ret = printf("7. st: Here is a hex: %x\n", -42);
	assert(ft_ret == stdio_ret);
	
	ft_ret = ft_printf("8. ft: Here is a hex: %x\n", INT_MAX);
	stdio_ret = printf("8. st: Here is a hex: %x\n", INT_MAX);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("9. ft: Here is an uppercase hex: %X\n", INT_MIN);
	stdio_ret = printf("9. st: Here is an uppercase hex: %X\n", INT_MIN);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("9. ft: Here is an uppercase hex: %X\n", 0);
	stdio_ret = printf("9. st: Here is an uppercase hex: %X\n", 0);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("9. ft: Here is an uppercase hex: %X\n", -42);
	stdio_ret = printf("9. st: Here is an uppercase hex: %X\n", -42);
	assert(ft_ret == stdio_ret);

	ft_ret = ft_printf("10. ft: Here is a percentage sign: %%\n");
	stdio_ret = printf("10. st: Here is a percentage sign: %%\n");
	assert(ft_ret == stdio_ret);

	uns = 42;
	ft_ret = ft_printf("11. ft: Here is an unsigned dec: %u\n", uns);
	stdio_ret = printf("11. st: Here is an unsigned dec: %u\n", uns);
	assert(ft_ret == stdio_ret);
}

void	test_bonus(void)
{
	assert(ft_printf("\nHex with dash: %#x\n", 42)
	== printf("\nHex with dash: %#x\n", 42));

	assert(ft_printf("\nHex with dash: %#X\n", -42)
	== printf("\nHex with dash: %#X\n", -42));

	assert(ft_printf("\nDec with space: % d\n", 0)
	== printf("\nDec with space: % d\n", 0));

	assert(ft_printf("\nDec without space: %i\n", -23)
	== printf("\nDec without space: %i\n", -23));

	assert(ft_printf("\nDec with space: % i\n", -23)
	== printf("\nDec with space: % i\n", -23));

	assert(ft_printf("\nDec with space: % d\n", INT_MIN)
	== printf("\nDec with space: % d\n", INT_MIN));

	assert(ft_printf("\nDec with space: % i\n", -1)
	== printf("\nDec with space: % i\n", -1));
}


int	main(int argc, char *argv[])
{
	int	nb;
	int	ret;
	char *str;

	printf("\n\033[0;32m************************TEST UTILS****************************\n");
	printf("\033[0m\n");
	test_utils();
	if (argc < 2)
		return (1);
	printf("\n\033[0;32m************************SOME TESTS****************************\n");
	printf("\033[0m\n");
	str = argv[1];
	nb = ft_strlen(str);
	ret = ft_printf("My ft_printf: Here is an int: \t\t%d\n", 0);
	printf("Return value: \t\t\t%d\n", ret);
	ret = printf("stdio printf: Here is an int: \t\t%d\n", 0);
	printf("Return value: \t\t\t%d\n", ret);
	ret = ft_printf("My ft_printf: Here is an int: \t\t%d\n", 9);
	printf("Return value: \t\t\t%d\n", ret);
	ret = printf("stdio printf: Here is an int: \t\t%d\n", 9);
	printf("Return value: \t\t\t%d\n", ret);
	ret = ft_printf("My ft_printf: Here is an int: \t\t%d\n", (-1234567890));
	printf("Return value: \t\t\t%d\n", ret);
	ret = printf("stdio printf: Here is an int: \t\t%d\n", (-1234567890));
	printf("Return value: \t\t\t%d\n", ret);
	ret = ft_printf("My ft_printf: Here is an int: \t\t%d\n", INT_MIN);
	printf("Return value: \t\t\t%d\n", ret);
	ret = printf("stdio printf: Here is an int: \t\t%d\n", INT_MIN);
	printf("Return value: \t\t\t%d\n", ret);
	ft_printf("My ft_printf: Here is a char: \t\t%c\n", *str);
	printf("stdio.h printf: Here is a char: \t%d\n", *str);
	printf("\n\033[0;32m************************TEST CONVERSIONS**********************\n");
	printf("\033[0m\n");
	test_conversions();
	printf("\n\033[0;32m************************TEST BONUS**********************\n");
	printf("\033[0m\n");
	test_bonus();
	return (0);
}
