/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:20:28 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/10 13:02:49 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*t;

	t = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char) c)
			t = s;
		s++;
	}
	if ((unsigned char) c == '\0')
		t = s;
	return ((char *) t);
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
	printf("%s", ft_strrchr(s, c));
	return (0);
}*/
