/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:33:11 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/09 15:22:28 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	result;

	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	neg = 1;
	if (*nptr == '-')
	{
		neg = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (neg * result);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	nb1;
	int	nb2;

	if (argc < 2)
		return (1);
	nb1 = ft_atoi(argv[1]);
	nb2 = atoi(argv[1]);
	printf("My function: %d\n", nb1);
	printf("Lib function: %d\n", nb2);
	return (0); 
}*/
