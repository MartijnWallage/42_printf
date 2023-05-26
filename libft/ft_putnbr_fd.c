/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:24:44 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/26 20:27:12 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursion(unsigned long long nb, unsigned int base, int fd)
{
	int		chars_written;
	char	c;
	char	*baseset;

	chars_written = 0;
	baseset = "0123456789abcdefgh";
	if (nb >= base)
		chars_written += recursion(nb / base, base, fd);
	c = baseset[nb % base];
	ft_putchar_fd(c, fd);
	chars_written++;
	return (chars_written);
}

int	ft_putnbr_base_fd(long long n, unsigned int base, int fd)
{
	unsigned long long	nb;

	if (n == LLONG_MIN)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned long long)LLONG_MAX + 1;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned long long)(n * -1);
	}
	else
		nb = (unsigned long long) n;
	return (recursion(nb, base, fd));
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
