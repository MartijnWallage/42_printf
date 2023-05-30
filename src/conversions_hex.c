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

void	ft_print_hex(t_print *tab, char *base, char *zerox)
{
	unsigned int	nb;
	unsigned int	numdigits;
	unsigned int	numlen;
	unsigned int	paddinglen;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0)
		tab->hash = 0;
	numdigits = ft_numdigits(nb, 16);
	numlen = ft_max(tab->precision, numdigits);
	if (nb == 0 && tab->point && !tab->precision)
		numlen = 0;
	paddinglen = ft_max(0, tab->width - numlen - 2 * (tab->hash));
	if (tab->hash && tab->padding == '0')
		tab->len += write(1, zerox, 2);
	if (!tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
	if (tab->hash && tab->padding == ' ')
		tab->len += write(1, zerox, 2);
	if (tab->point)
		tab->len += put_padding(tab, '0', tab->precision - numdigits);
	if (numlen)
		tab->len += ft_putnbr_base(nb, base);
	if (tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
}

void	ft_print_pnt(t_print *tab)
{
	void	*ptr;
	size_t	nb;
	unsigned int	numdigits;
	unsigned int	paddinglen;
	unsigned int	numlen;

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
	numdigits = ft_numdigits(nb, 16);
	numlen = ft_max(tab->precision, numdigits) + 2;
	paddinglen = ft_max(0, tab->width - numlen);
	if (tab->padding == '0')
		tab->len += write(1, "0x", 2);
	if (!tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ')
		tab->len += write(1, "0x", 2);
	if (tab->point)
		tab->len += put_padding(tab, '0', tab->precision - numdigits);
	tab->len += ft_putnbr_base(nb, HEX_LOWER);
	if (tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
}
