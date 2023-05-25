/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:38:46 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/04 11:41:33 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	uc;

	t = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		if (*t == uc)
			return ((char *) t);
		t++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	const char *s;
	int			c;

	if (argc < 3)
		return (1);
	s = (const char *) argv[1];
	c = (int) argv[2][0];
	printf("%s", ft_memchr(s, c, 5));
	return (0);
}*/
