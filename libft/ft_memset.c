/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:12:06 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/04 11:44:02 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) s;
	while (n-- > 0)
		*p++ = (unsigned char) c;
	return (s);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc < 3)
		return (1);
	printf("%s", (char *) ft_memset(argv[1], (int) argv[2][0], 4));
	return (0);
}*/
