/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:46:06 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/08 18:28:01 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Not the right number of arguments.");
		return (1);
	}
	char			str1[] = {0, 0, 2, -4};
	const char		str2[] = {0, 0, 2, -4};
	unsigned int	n = 4;

	printf("My function	: %d\n", ft_memcmp(str1, str2, n));
	printf("Library function: %d\n", memcmp(str1, str2, n));
	return (0);
}*/
