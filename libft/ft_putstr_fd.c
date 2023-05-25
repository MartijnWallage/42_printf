/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:59 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/05 17:22:21 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
/*
#include <fcntl.h>
int	main(int argc, char *argv[])
{
	int	fd;

	if (argc < 2)
		return (1);
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	ft_putstr_fd(argv[1], fd);
	return (0);
}*/
