/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:22:36 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/29 17:46:09 by mwallage         ###   ########.fr       */
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
	while (*set && *set != c)
		set++;
	return (*set == c);
}

size_t	ft_abs(ssize_t nbr)
{
	long long	temp;

	temp = (long long) nbr;
	if (nbr < 0)
	{
		temp = -temp;
		return ((size_t)temp);
	}
	return ((size_t)nbr);
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

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}