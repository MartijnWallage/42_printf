/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:43:11 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/09 15:18:05 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		size;

	size = 0;
	while (s[size])
		size++;
	size++;
	copy = (char *) malloc(size * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (size--)
		copy[size] = s[size];
	return (copy);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*str;

	if (argc != 2)
		return (1);
	str = argv[1];
	printf("%s", ft_strdup(str));
}*/
