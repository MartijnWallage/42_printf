/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:22:36 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/25 21:02:27 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned long	ft_abs(int nb)
{
	if (nb == INT_MIN)
		return ((unsigned long)INT_MAX + 1);
	if (nb < 0)
		return ((unsigned long)(nb * -1));
	else
		return ((unsigned long) nb);
}

unsigned long	ft_power(unsigned int base, unsigned int power)
{
	unsigned long	result;

	if (power == 0)
		return (1);
	result = base;
	while (--power)
		result *= base;
	return (result);
}

unsigned int	ft_log(unsigned int base, unsigned long log)
{
	unsigned int	power;

	if (log <= 1)
		return (0);
	power = 1;
	while (ft_power(base, power) < log)
		power++;
	power--;
	return (power);
}

