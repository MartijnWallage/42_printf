/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:07:08 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/05 17:15:14 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	ft_putchar_fd('a', fd);
	close(fd);
	return (0);
}*/
