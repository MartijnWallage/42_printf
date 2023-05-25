/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:49:47 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/04 12:11:21 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*t;

	t = (char *) s;
	while (n--)
		*t++ = 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*str = malloc(12);

	*str = 'A';
	printf("%s\n", str);
	ft_bzero(str, 2);
	printf("%s\n", str);
	return (0);
}*/
