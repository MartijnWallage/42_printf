/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:28:34 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/27 20:23:20 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static unsigned int	putnbr_recursion(size_t nbr, char *base,
	unsigned int baselen)
{
	int		chrs_written;
	char	c;

	chrs_written = 0;
	if (nbr >= baselen)
		chrs_written += putnbr_recursion(nbr / baselen, base, baselen);
	c = base[nbr % baselen];
	chrs_written += write(1, &c, 1);
	return (chrs_written);
}

unsigned int	ft_putnbr_base(ssize_t nbr, char *base)
{
	unsigned int	chrs_written;
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	chrs_written = 0;
	if (nbr < 0 && baselen == 10)
	{
		chrs_written += write(1, "-", 1);
		nbr = ft_abs(nbr);
	}
	chrs_written += putnbr_recursion(nbr, base, baselen);
	return (chrs_written);
}
