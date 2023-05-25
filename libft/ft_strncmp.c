/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:42:44 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/10 13:07:45 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n > 1 && *str1 == *str2)
	{
		if (*str1 == '\0')
			return (0);
		++str1;
		++str2;
		--n;
	}
	return ((int)(*str1 - *str2));
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Not the right number of arguments.");
		return (1);
	}
	char			*str1 = "\0";
	char			*str2 = "\200";
	unsigned int	n = 1;

	printf("My function	: %s, %d, %d\n", str1, str2, ft_strncmp(str1, str2, n));
	printf("Library function: %s, %d, %d\n", str1, str2, strncmp(str1, str2, n));
	return (0);
}*/
