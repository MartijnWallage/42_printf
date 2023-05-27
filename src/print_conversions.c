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

unsigned int	ft_putnbr_base(ssize_t nbr, char *base)
{
	int		chrs_written;
	int		baselen;
	int		digits;
	int		div;
	char	c;

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
			nbr = twos_complement(nbr);
	}
	digits = ft_log_base(nbr, baselen);
	chrs_written += digits;
	while (digits--)
	{
		div = ft_pow(baselen, digits - 1);
		c = base[nbr / div];
		chrs_written = write(1, &c, 1);
		nbr %= div;
	}
	return (chrs_written);
}