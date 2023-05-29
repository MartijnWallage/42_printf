/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:40:00 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/29 16:57:29 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#define HEX_LOWER	"0123456789abcdef"
#define HEX_UPPER	"0123456789ABCDEF"

void	ft_print_hex(t_print *tab)
{
	unsigned int	nb;
	unsigned int	numlen;
	unsigned int	paddinglen;

	nb = va_arg(tab->args, unsigned int);
	numlen = ft_numlen(tab, nb, 16);
	paddinglen = tab->width - numlen - 2 * (tab->hash);
	if (tab->padding == '0' && tab->hash && nb != 0)
		tab->total_len += write(1, "0x", 2);
	if (!tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ' && tab->hash && nb != 0)
		tab->total_len += write(1, "0x", 2);
	if (tab->point)
		tab->total_len += put_padding(tab, '0', tab->precision);
	tab->total_len += ft_putnbr_base(nb, HEX_LOWER);
	if (tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
}

void	ft_print_hex_upper(t_print *tab)
{
	unsigned int	nb;
	unsigned int	numlen;
	unsigned int	paddinglen;

	nb = va_arg(tab->args, unsigned int);
	numlen = ft_numlen(tab, nb, 16);
	paddinglen = tab->width - numlen - 2 * (tab->hash);
	if (tab->padding == '0' && tab->hash && nb != 0)
		tab->total_len += write(1, "0X", 2);
	if (!tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ' && tab->hash && nb != 0)
		tab->total_len += write(1, "0X", 2);
	if (tab->point)
		tab->total_len += put_padding(tab, '0', tab->precision);
	tab->total_len += ft_putnbr_base(nb, HEX_UPPER);
	if (tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
}

void	ft_print_pnt(t_print *tab)
{
	void			*ptr;
	size_t			nb;
	unsigned int	paddinglen;
	unsigned int	numlen;

	ptr = va_arg(tab->args, void *);
	if (ptr == NULL)
	{
		paddinglen = ft_max(0, tab->width - 5);
		if (!tab->dash)
			tab->total_len += put_padding(tab, ' ', paddinglen);
		tab->total_len += write(1, "(nil)", 5);
		if (tab->dash)
			tab->total_len += put_padding(tab, ' ', paddinglen);
		return ;
	}
	nb = (size_t) ptr;
	numlen = ft_max(tab->precision, ft_numdigits(tab, nb, 16)) + 2;
	paddinglen = ft_max(0, tab->width - numlen);
	if (tab->padding == '0')
		tab->total_len += write(1, "0x", 2);
	if (!tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ')
		tab->total_len += write(1, "0x", 2);
	if (tab->point)
		tab->total_len += put_padding(tab, '0', tab->precision);
	tab->total_len += ft_putnbr_base(nb, HEX_LOWER);
	if (tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
}
