/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:33:57 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/26 21:21:34 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->total_len += write(1, &c, 1);
}

void	ft_print_str(t_print *tab)
{
	char	*str;

	str = va_arg(tab->args, char*);
	if (str == NULL)
	{
		tab->total_len += write(1, "(null)", 6);
		return ;
	}
	ft_putstr_fd(str, 1);
	tab->total_len += ft_strlen(str);
}

void	ft_print_pnt(t_print *tab)
{
	void		*ptr;
	long long	nb;

	ptr = va_arg(tab->args, void*);
	if (ptr == NULL)
	{
		tab->total_len += write(1, "(nil)", 5);
		return ;
	}
	nb = (long long) ptr;
	tab->total_len += write(1, "0x", 2);
	tab->total_len += ft_putnbr_base_fd(nb, 16, 1);
}

void	ft_print_int(t_print *tab)
{
	int	nb;

	nb = va_arg(tab->args, int);
	tab->total_len += ft_putnbr_base_fd(nb, 10, 1);
	if (nb < 0)
		tab->total_len++;
}

void	ft_print_und(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	ft_putnbr_base_fd(nb, 10, 1);
	tab->total_len += ft_log(10, nb) + 1;
}

void	ft_print_hex(t_print *tab)
{
	int				nb;
	unsigned int	unb;
	unsigned int	mask;

	nb = va_arg(tab->args, int);
	unb = (unsigned int)nb;
	mask = 1 << (sizeof(int) * 8 - 1);
	if (nb < 0)
		unb = unb | (~mask + 1);
	tab->total_len += ft_putnbr_base_fd(unb, 16, 1);
}

void	ft_print_HEX(t_print *tab)
{
	int				nb;
	int				i;
	int				upper;
	unsigned int	unb;
	unsigned int	mask;
	char			*str;

	nb = va_arg(tab->args, int);
	unb = (unsigned int)nb;
	mask = 1 << (sizeof(int) * 8 - 1);
	if (nb < 0)
		unb = unb | (~mask + 1);
	printf("unb = %ld\n", unb);
	str = ft_itoa_base(unb, 16);
	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		upper = ft_toupper(str[i]);
		tab->total_len += write(1, &upper, 1);
		i++;
	}
	free(str);
}

void	ft_print_perc(t_print *tab)
{
	char	c;

	c = '%';
	tab->total_len += write(1, &c, 1);
}
