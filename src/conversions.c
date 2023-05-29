/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:33:57 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/27 18:45:12 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#define DEC	"0123456789"

void	ft_print_char(t_print *tab)
{
	char	c;
	int		padding_len;

	c = va_arg(tab->args, int);
	padding_len = tab->width - 1;
	if (padding_len > 0 && !tab->dash)
		tab->total_len += put_padding(tab, ' ', padding_len);
	tab->total_len += write(1, &c, 1);
	if (padding_len > 0 && tab->dash)
		tab->total_len += put_padding(tab, ' ', padding_len);
}

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		padding_len;
	int		strlen;

	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->total_len += write(1, "(null)", 6);
		return ;
	}
	strlen = ft_strlen(str);
	if (tab->point)
		strlen = ft_min(strlen, tab->precision);
	padding_len = tab->width - strlen;
	if (padding_len > 0 && !tab->dash)
		tab->total_len += put_padding(tab, ' ', padding_len);
	tab->total_len += ft_putstr(str, strlen);
	if (padding_len > 0 && tab->dash)
		tab->total_len += put_padding(tab, ' ', padding_len);
}

void	ft_print_int(t_print *tab)
{
	int				nb;
	int				len;
	int				padding_len;
	unsigned int	unb;

	nb = va_arg(tab->args, int);
	tab->neg = nb < 0;
	unb = (unsigned int)nb;
	if (tab->neg)
		unb = (unsigned int)-nb;
	if (tab->padding == '0')
		tab->total_len += put_sign_or_space(tab);
	len = num_digits(unb, 10);
	tab->precision -= len;
	if (tab->precision < 0)
		tab->precision = 0;
	if (tab->point)
		len += tab->precision;
	padding_len = tab->width - len - (tab->neg || tab->space || tab->sign);
	if (len > 0 && !tab->dash)
		tab->total_len += put_padding(tab, tab->padding, padding_len);
	if (tab->padding == ' ')
		tab->total_len += put_sign_or_space(tab);
	if (tab->point)
		tab->total_len += put_padding(tab, '0', tab->precision);
	tab->total_len += ft_putnbr_base(nb, DEC);
	if (len > 0 && tab->dash)
		tab->total_len += put_padding(tab, tab->padding, padding_len);
}

void	ft_print_und(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	tab->total_len += ft_putnbr_base(nb, DEC);
}

void	ft_print_perc(t_print *tab)
{
	char	c;

	c = '%';
	tab->total_len += write(1, &c, 1);
}
