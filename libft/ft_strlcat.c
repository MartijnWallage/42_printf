/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:58:13 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/03 10:48:59 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dest_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] && i < size - dest_len - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Not the right number of arguments.");
		return (1);
	}
	char			*src;
	char			dest[12] = "Hel";
	unsigned int	size = 5;

	src = argv[1];
	printf("%u, %s, %s", (unsigned int) ft_strlcat(dest, src, size), dest, src);
	return (0);
}*/
