#include "../inc/ft_printf.h"

unsigned int	ft_putstr(char *str)
{
	unsigned int	chrs_written;

	chrs_written = 0;
	while (*str)
	{
		chrs_written += write(1, str, 1);
		str++;
	}
	return (chrs_written);
}

#include <stdio.h>
static unsigned int	putnbr_recursion(ssize_t nbr, char *base, unsigned int baselen)
{
	int		chrs_written;
	char	c;

	chrs_written = 0;
	if (nbr < 0)
		printf("Nbr before recursion = %li\n", nbr);
	if (ft_abs(nbr) >= baselen)
		chrs_written += putnbr_recursion(nbr / baselen, base, baselen);
	c = base[ft_abs(nbr % baselen)];
	printf("\nNbr: %x, baselen: %d, nbr %% baselen: %d\n", nbr, baselen, nbr % baselen);
	chrs_written += write(1, &c, 1);
	return (chrs_written);
}

unsigned int	ft_putnbr_base(ssize_t nbr, char *base)
{
	unsigned int	chrs_written;
	unsigned int	baselen;

	chrs_written = 0;
	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	if (nbr < 0)
	{
		if (baselen == 10)
		{
			chrs_written += write(1, "-", 1);
			nbr = ft_abs(nbr);
		}
		else
		{
			nbr = twos_complement(nbr);
			printf("Nbr = twos_complement: %li\n", nbr);
		}
	}
	chrs_written += putnbr_recursion(nbr, base, baselen);
	return (chrs_written);
}