/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:33:57 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/29 18:59:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;
	int		paddinglen;

	c = va_arg(tab->args, int);
	paddinglen = tab->width - 1;
	if (paddinglen > 0 && !tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
	tab->len += write(1, &c, 1);
	if (paddinglen > 0 && tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
}

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		paddinglen;
	int		strlen;

	str = va_arg(tab->args, char *);
	strlen = ft_strlen(str);
	if (str == NULL)
		strlen = 6;
	if (tab->point)
		strlen = ft_min(strlen, tab->precision);
	paddinglen = ft_max(0, tab->width - strlen);
	if (!tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
	tab->len += ft_putstr(str, strlen);
	if (tab->dash)
		tab->len += put_padding(tab, ' ', paddinglen);
}

void	ft_print_int(t_print *tab)
{
	int				nb;
	int				numlen;
	int				numdigits;
	int				paddinglen;
	unsigned int	unb;

	nb = va_arg(tab->args, int);
	tab->neg = nb < 0;
	unb = (unsigned int)nb;
	if (tab->neg)
		unb = (unsigned int)-nb;
	numdigits = ft_numdigits(unb, 10);
	tab->precision = ft_max(0, tab->precision - numdigits);
	numlen = numdigits + tab->precision + (tab->neg || tab->space || tab->sign);
	paddinglen = ft_max(0, tab->width - numlen);
	if (tab->padding == '0')
		tab->len += put_sign_or_space(tab);
	if (!tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ')
		tab->len += put_sign_or_space(tab);
	if (tab->point)
		tab->len += put_padding(tab, '0', tab->precision);
	tab->len += ft_putnbr_base(unb, DEC);
	if (tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
}

void	ft_print_uns(t_print *tab)
{
	unsigned int	nb;
	int				numlen;
	int				paddinglen;

	nb = va_arg(tab->args, unsigned int);
	numlen = ft_max(ft_numdigits(nb, 10), tab->precision);
	paddinglen = tab->width - numlen;
	if (!tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
	if (tab->point)
		tab->len += put_padding(tab, '0', tab->precision);
	tab->len += ft_putnbr_base(nb, DEC);
	if (tab->dash)
		tab->len += put_padding(tab, tab->padding, paddinglen);
}

void	ft_print_perc(t_print *tab)
{
	char	c;

	c = '%';
	tab->len += write(1, &c, 1);
}
