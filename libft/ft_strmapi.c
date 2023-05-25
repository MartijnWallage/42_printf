/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:31:25 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/05 16:55:57 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		size;
	int		i;

	size = ft_strlen(s);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char uppercase(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    else
        return c;
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*str;

	if (argc < 2)
		return (1);
	str = ft_strmapi(argv[1], uppercase);
	printf("%s\n%s\n", argv[1], str);
	return (0);
}*/
