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
		tab->total_len += put_padding(tab, padding_len);
	tab->total_len += write(1, &c, 1);
	if (padding_len > 0 && tab->dash)
		tab->total_len += put_padding(tab, padding_len);
}

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		padding_len;

	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->total_len += write(1, "(null)", 6);
		return ;
	}
	padding_len = tab->width - ft_strlen(str);
	if (padding_len > 0 && !tab->dash)
		tab->total_len += put_padding(tab, padding_len);
	tab->total_len += ft_putstr(str);
	if (padding_len > 0 && tab->dash)
		tab->total_len += put_padding(tab, padding_len);
}

void	ft_print_int(t_print *tab)
{
	int	nb;
	int	len;

	nb = va_arg(tab->args, int);
	len = num_digits(nb, 10);
	if (nb == INT_MIN)
		printf("\n%d has %d digits\n", INT_MIN, len);
	if (tab->sign && nb >= 0)
	{
		tab->total_len += write(1, "+", 1);
		len++;
	}
	else if (tab->space && nb >= 0)
	{
		tab->total_len += write(1, " ", 1);
		len++;
	}
	else if (nb < 0 && tab->zero)
		tab->total_len += write(1, "-", 1);
	if (nb < 0)
		len++;
	len = tab->width - len;
	if (len > 0 && !tab->dash)
		tab->total_len += put_padding(tab, len);
	if (nb < 0 && !tab->zero)
		tab->total_len += write(1, "-", 1);
	tab->total_len += ft_putnbr_base(nb, DEC);
	if (len > 0 && tab->dash)
		tab->total_len += put_padding(tab, len);
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
