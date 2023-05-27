/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:40:00 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/27 20:21:45 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#define HEX			"0123456789abcdef"
#define HEX_UPPER	"0123456789ABCDEF"

void	ft_print_hex(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, int);
	tab->total_len += ft_putnbr_base(nb, HEX);
}

void	ft_print_hex_upper(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, int);
	tab->total_len += ft_putnbr_base(nb, HEX_UPPER);
}

void	ft_print_pnt(t_print *tab)
{
	void	*ptr;
	size_t	nb;

	ptr = va_arg(tab->args, void *);
	if (ptr == NULL)
	{
		tab->total_len += write(1, "(nil)", 5);
		return ;
	}
	nb = (size_t) ptr;
	tab->total_len += write(1, "0x", 2);
	tab->total_len += ft_putnbr_base(nb, HEX);
}
