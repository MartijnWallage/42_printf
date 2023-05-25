/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:59:52 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/16 18:35:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	s;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	s = nmemb * size;
	if (s / size != nmemb)
		return (NULL);
	ptr = malloc(s);
	if (ptr != NULL)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
#include <assert.h>
#include <stdio.h>
int	main(void)
{
	char	*str;
	char	*cpy;

	str = ft_calloc(12, 0);
	cpy = calloc(12, 0);
	printf("%s---\n", str);
	printf("%s---\n", cpy);
	assert(ft_strncmp(str, cpy, 12) == 0);
	*str = 'H';
	*cpy = 'H';
	printf("%p---\nlen:%zu\n", str, ft_strlen(str));
	printf("%s---\n", cpy);
	assert(ft_strncmp(str, cpy, 12) == 0);
	free(cpy);
	free(str);
	return (0);
}*/
