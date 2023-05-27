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

#define	dec	"0123456789"
#define hex "0123456789abcdef"
#define HEX "0123456789ABCDEF"

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
	tab->total_len += ft_putstr(str);
}

void	ft_print_pnt(t_print *tab)
{
	void	*ptr;
	size_t	nb;

	ptr = va_arg(tab->args, void*);
	if (ptr == NULL)
	{
		tab->total_len += write(1, "(nil)", 5);
		return ;
	}
	nb = (size_t) ptr;
	tab->total_len += write(1, "0x", 2);
	tab->total_len += ft_putnbr_base(nb, hex);
}

void	ft_print_int(t_print *tab)
{
	int	nb;

	nb = va_arg(tab->args, int);
	tab->total_len += ft_putnbr_base(nb, dec);
}

void	ft_print_und(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	tab->total_len += ft_putnbr_base(nb, dec);
}

void	ft_print_hex(t_print *tab)
{
	size_t	nb;

	nb = va_arg(tab->args, int);
	tab->total_len += ft_putnbr_base(nb, hex);
}

void	ft_print_HEX(t_print *tab)
{
	size_t	nb;

	nb = va_arg(tab->args, int);
	tab->total_len += ft_putnbr_base(nb, HEX);
}

void	ft_print_perc(t_print *tab)
{
	char	c;

	c = '%';
	tab->total_len += write(1, &c, 1);
}
