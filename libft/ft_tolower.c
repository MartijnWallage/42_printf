/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:05:20 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/04 11:35:42 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}
/*
#include <unistd.h>
int	main(int argc, char *argv[])
{
	char	*str;
	char	c;

	if (argc < 2)
		return (1);
	str = argv[1];
	while (*str)
	{
		c = (char) ft_tolower(*str);
		write(1, &c, 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}*/
