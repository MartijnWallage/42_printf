/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:22:31 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/05 17:24:11 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}
/*
#include <fcntl.h>
int	main(int argc, char *argv[])
{
	int	fd;

	if (argc < 2)
		return (1);
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	ft_putendl_fd(argv[1], fd);
	return (0);
}*/
