/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:40:00 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/29 18:15:36 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_hex(t_print *tab)
{
	unsigned int	nb;
	unsigned int	numlen;
	unsigned int	paddinglen;

	nb = va_arg(tab->args, unsigned int);
	numlen = ft_max(tab->precision, ft_numdigits(nb, 16));
	paddinglen = tab->width - numlen - 2 * (tab->hash);
	if (tab->padding == '0' && tab->hash && nb != 0)
		tab->len += write(1, "0x", 2);
	if (!tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ' && tab->hash && nb != 0)
		tab->len += write(1, "0x", 2);
	if (tab->point)
		tab->len += put_padding(tab, '0', tab->precision);
	tab->len += ft_putnbr_base(nb, HEX_LOWER);
	if (tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
}

void	ft_print_hex_upper(t_print *tab)
{
	unsigned int	nb;
	unsigned int	numlen;
	unsigned int	paddinglen;

	nb = va_arg(tab->args, unsigned int);
	numlen = ft_max(tab->precision, ft_numdigits(nb, 16));
	paddinglen = tab->width - numlen - 2 * (tab->hash);
	if (tab->padding == '0' && tab->hash && nb != 0)
		tab->len += write(1, "0X", 2);
	if (!tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ' && tab->hash && nb != 0)
		tab->len += write(1, "0X", 2);
	if (tab->point)
		tab->len += put_padding(tab, '0', tab->precision);
	tab->len += ft_putnbr_base(nb, HEX_UPPER);
	if (tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
}

void	ft_print_pnt(t_print *tab)
{
	void	*ptr;
	size_t	nb;
	int		paddinglen;
	int		numlen;

	ptr = va_arg(tab->args, void *);
	if (ptr == NULL)
	{
		paddinglen = ft_max(0, tab->width - 5);
		if (!tab->dash)
			tab->len += put_padding(tab, ' ', paddinglen);
		tab->len += write(1, "(nil)", 5);
		if (tab->dash)
			tab->len += put_padding(tab, ' ', paddinglen);
		return ;
	}
	nb = (size_t) ptr;
	if (nb < 0)
		numlen = 18;
	else
		numlen = ft_max(tab->precision, ft_numdigits(nb, 16)) + 2;
	paddinglen = ft_max(0, tab->width - numlen);
	if (tab->padding == '0')
		tab->len += write(1, "0x", 2);
	if (!tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ')
		tab->len += write(1, "0x", 2);
	if (tab->point)
		tab->len += put_padding(tab, '0', tab->precision);
	tab->len += ft_putnbr_base(nb, HEX_LOWER);
	if (tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
}
