/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:24:44 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/26 14:25:51 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursion(unsigned int nb, unsigned int base, int fd)
{
	char	c;

	if (nb >= base)
		recursion(nb / base, base, fd);
	c = nb % base + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_base_fd(long n, unsigned int base, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int) n;
	recursion(nb, base, fd);
}
/*
#include <fcntl.h>
#include <unistd.h>
int	main(int argc, char *argv[])
{
	int	nb;
	int fd;

	if (argc < 2)
		return (1);
	nb = ft_atoi(argv[1]);
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	ft_putnbr_fd(nb, fd);
	close(fd);
	return (0);
}*/
