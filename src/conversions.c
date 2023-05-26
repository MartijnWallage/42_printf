/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:33:57 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/26 15:36:46 by mwallage         ###   ########.fr       */
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
	ft_putstr_fd(str, 1);
	tab->total_len += ft_strlen(str);
}

void	ft_print_pnt(t_print *tab)
{
	void		*ptr;
	long long	val;

	ptr = va_arg(tab->args, void*);
	val = (long long) ptr;
	ft_putnbr_base_fd(val, 16, 1);
	tab->total_len += ft_log(16, val) + 1;
}

void	ft_print_int(t_print *tab)
{
	int	nb;

	nb = va_arg(tab->args, int);
	ft_putnbr_base_fd(nb, 10, 1);
	tab->total_len += ft_log(10, ft_abs(nb)) + 1;
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
	int	nb;

	nb = va_arg(tab->args, int);
	ft_putnbr_base_fd(nb, 16, 1);		// This function needs to be re-written. It needs to use a string for the base chars.
	tab->total_len += ft_log(16, nb) + 1;
	if (nb < 0)
		tab->total_len++;
}

void	ft_print_HEX(t_print *tab)
{
	int		nb;
	char	*str;
	char	upper;

	nb = va_arg(tab->args, int);
	str = ft_itoa_base(nb, 16);
	if (str == NULL)
		return ;
	while (str++)
	{
		upper = ft_toupper(*str);
		tab->total_len += write(1, &upper, 1);
	}
	free(str);
}

void	ft_print_perc(t_print *tab)
{
	char	c;

	c = '%';
	tab->total_len += write(1, &c, 1);
}
