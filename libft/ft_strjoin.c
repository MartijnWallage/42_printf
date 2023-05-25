/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:55:19 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/04 13:17:10 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*result;

	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined == NULL)
		return (NULL);
	result = joined;
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	*joined = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "Hello ";
	char	*s2 = "world!";
	char	*joined;

	joined = ft_strjoin(s1, s2);
	printf("%s", joined);
	free(joined);
	return (0);
}*/
