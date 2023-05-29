/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:33:57 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/29 16:09:30 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#define DEC	"0123456789"

void	ft_print_char(t_print *tab)
{
	char	c;
	int		paddinglen;

	c = va_arg(tab->args, int);
	paddinglen = tab->width - 1;
	if (paddinglen > 0 && !tab->dash)
		tab->total_len += put_padding(tab, ' ', paddinglen);
	tab->total_len += write(1, &c, 1);
	if (paddinglen > 0 && tab->dash)
		tab->total_len += put_padding(tab, ' ', paddinglen);
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
	paddinglen = tab->width - strlen;
	if (paddinglen > 0 && !tab->dash)
		tab->total_len += put_padding(tab, ' ', paddinglen);
	tab->total_len += ft_putstr(str, strlen);
	if (paddinglen > 0 && tab->dash)
		tab->total_len += put_padding(tab, ' ', paddinglen);
}

void	ft_print_int(t_print *tab)
{
	int				nb;
	int				numlen;
	int				paddinglen;
	unsigned int	unb;

	nb = va_arg(tab->args, int);
	tab->neg = nb < 0;
	unb = (unsigned int)nb;
	if (tab->neg)
		unb = (unsigned int)-nb;
	if (tab->padding == '0')
		tab->total_len += put_sign_or_space(tab);
	numlen = ft_numlen(tab, unb, 10);
	paddinglen = tab->width - numlen - (tab->neg || tab->space || tab->sign);
	if (!tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
	if (tab->padding == ' ')
		tab->total_len += put_sign_or_space(tab);
	if (tab->point)
		tab->total_len += put_padding(tab, '0', tab->precision);
	tab->total_len += ft_putnbr_base(unb, DEC);
	if (tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
}

void	ft_print_uns(t_print *tab)
{
	unsigned int	nb;
	int				numlen;
	int				paddinglen;

	nb = va_arg(tab->args, unsigned int);
	numlen = ft_numlen(tab, nb, 10);
	paddinglen = tab->width - numlen;
	if (!tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
	if (tab->point)
		tab->total_len += put_padding(tab, '0', tab->precision);
	tab->total_len += ft_putnbr_base(nb, DEC);
	if (tab->dash)
		tab->total_len += put_padding(tab, tab->padding, paddinglen);
}

void	ft_print_perc(t_print *tab)
{
	char	c;

	c = '%';
	tab->total_len += write(1, &c, 1);
}
