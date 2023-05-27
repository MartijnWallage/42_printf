/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:22:36 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/27 20:25:39 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned int	ft_strlen(const char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_in_set(const char c, const char *set)
{
	while (*set != c)
		set++;
	return (*set);
}

size_t	ft_abs(ssize_t nbr)
{
	if (nbr < 0)
		return ((size_t)(nbr * -1));
	return ((size_t)nbr);
}
/*
unsigned int	ft_log2(unsigned int n)
{
	unsigned int	result;

	if (n == 0)
		return (0);
	result = 0;
	while (n >>= 1)
		result++;
	return (result);
}

unsigned int	ft_log_base(unsigned int base, unsigned int n)
{
	unsigned int	log2n;
	unsigned int	log2base;

	log2n = ft_log2(n);
	log2base = ft_log2(base);
	if (log2base == 0)
		return (0);
    return (log2n / log2base);
}

unsigned int	ft_pow(unsigned int base, unsigned int exponent)
{
	unsigned int	result;

	if (exponent == 0)
		return (1);
	if (base == 0)
		return (0);
	result = base;
	while (--exponent)
		result *= base;
	return (result);
} */