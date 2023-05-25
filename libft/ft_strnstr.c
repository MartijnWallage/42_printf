/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:07:26 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/04 11:40:10 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	match(const char *big, const char *little, size_t len)
{
	while (len && *big == *little)
	{
		if (*big == '\0')
			return (1);
		big++;
		little++;
		len--;
	}
	return (*little == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == 0)
		return ((char *) big);
	while (len && *big)
	{
		if (match(big, little, len))
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
	if (argc < 3)
		return (1);
	printf("ft_strnstr:\t%s\n", ft_strnstr(argv[1], argv[2], 0));
	printf("strstr:\t\t%s\n", strstr(argv[1], argv[2]));
	return (0);
}*/
