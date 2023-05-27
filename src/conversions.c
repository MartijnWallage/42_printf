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

	c = va_arg(tab->args, int);
	tab->total_len += write(1, &c, 1);
}

void	ft_print_str(t_print *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->total_len += write(1, "(null)", 6);
		return ;
	}
	tab->total_len += ft_putstr(str);
}

void	ft_print_int(t_print *tab)
{
	int	nb;

	nb = va_arg(tab->args, int);
	tab->total_len += ft_putnbr_base(nb, DEC);
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
