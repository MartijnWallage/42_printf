/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:16:15 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/30 18:17:02 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned int	get_unsigned_int(t_print *tab)
{
	int				nb;
	unsigned int	unb;

	nb = va_arg(tab->args, int);
	tab->neg = nb < 0;
	unb = (unsigned int)nb;
	if (tab->neg)
		unb = (unsigned int)-nb;
	return (unb);
}

int	ft_atoi_start_to_end(const char *str, int start, int end)
{
	int	nbr;
	int	power;

	nbr = 0;
	power = 1;
	while (--end >= start)
	{
		nbr += power * (str[end] - '0');
		power *= 10;
	}
	return (nbr);
}

unsigned int	ft_numdigits(size_t nbr, unsigned int baselen)
{
	unsigned int	count;

	if (baselen < 2)
		return (0);
	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		nbr /= baselen;
		count++;
	}
	while (nbr < 0)
	{
		nbr /= baselen;
		count++;
	}
	return (count);
}
