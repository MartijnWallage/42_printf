/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:21:10 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/17 13:45:17 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

static char	*empty_string(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slen;
	size_t	sublen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (empty_string());
	sublen = ft_min(len, slen - start);
	substr = malloc(sublen + 1);
	if (substr == NULL)
		return (NULL);
	substr[sublen] = '\0';
	i = start;
	while (sublen-- && s[i])
	{
		substr[i - start] = s[i];
		i++;
	}
	return (substr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "lorem ipsum dolor sit amet";
	char	*substr;

	substr = ft_substr(str, 7, 5);
	printf("%s----\n", substr);
	if (substr != NULL)
		free(substr);
	return (0);
}*/
