/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:01:09 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/03 17:42:29 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	printf("%d\n", ft_isalnum(argv[1][0]));
	return (0);
}*/
