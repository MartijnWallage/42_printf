/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:14:31 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/09 18:21:25 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	recursion(char *str, unsigned int nb)
{
	if (nb > 9)
		recursion(str, nb / 10);
	while (*str)
		str++;
	*str = nb % 10 + '0';
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	nb;
	unsigned int	div;
	unsigned int	digits;
	unsigned int	neg;

	neg = (n < 0);
	nb = (unsigned int)(n);
	if (neg)
		nb = (unsigned int)(n * -1);
	div = 1;
	digits = 1;
	while (nb / div > 9)
	{
		div *= 10;
		digits++;
	}
	result = malloc(digits + 1 + neg);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, digits + 1 + neg);
	if (neg)
		*result = '-';
	recursion(result, nb);
	return (result);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int		nb;
	char	*str;
	if (argc < 2)
		return (1);
	nb = -2147483648LL;
	str = ft_itoa(nb);	
	printf("ft_itoa: %saaa\nstrlen:%zu\n", str, ft_strlen(str));
	nb = -9874;
	free(str);
	str = ft_itoa(nb);	
	printf("ft_itoa: %saaa\nstrlen:%zu\n", str, ft_strlen(str));
	nb = atoi(argv[1]);
	free(str);
	str = ft_itoa(nb);
	printf("ft_itoa: %saaa\nstrlen:%zu\n", str, ft_strlen(str));
	if (str != NULL)
		free(str);
	return (0);
}*/
