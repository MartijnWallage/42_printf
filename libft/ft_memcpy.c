/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:03:15 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/09 18:02:35 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	str_dest = (unsigned char *) dest;
	str_src = (unsigned char *) src;
	while (n-- > 0)
		*str_dest++ = *str_src++;
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	const char		*src = "Hello world";
	unsigned char	*dest = malloc(12);

	printf("%s\n", src);
	printf("%s\n", (unsigned char *) ft_memcpy(dest, src, 6));
	printf("%s\n", dest);
	return (0);
}*/
