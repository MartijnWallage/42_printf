/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:38 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/10 13:05:53 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
	const char *s;
	int			c;

	if (argc < 3)
		return (1);
	s = (const char *) argv[1];
	c = (int) argv[2][0];
	printf("ft_strchr: \t%s\n", ft_strchr(s, c + 256));
	printf("strchr: \t%s\n", strchr(s, c + 256));
	return (0);
}*/
