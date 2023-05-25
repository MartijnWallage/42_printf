/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:58:12 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/05 17:06:32 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	uppercase(unsigned int index, char *s)
{
    if (*s >= 'a' && *s <= 'z')
        *s -= 'a' - 'A';
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*str;

	if (argc < 2)
		return (1);
	str = argv[1];
	ft_striteri(str, uppercase);
	printf("%s****\n", str);
	return (0);
}*/
