/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:07:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/26 15:30:39 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_init_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->dash = 0;
	tab->total_len = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->percent = 0;
	tab->space = 0;
}

int	ft_eval_format(t_print *tab, const char *format, int i)
{
	while (!is_in_set(format[i], "udcsupxX%"))
	{
		if (format[i] == '.')
			tab->point = 1;
		if (format[i] == '-')
			tab->dash = 1;
	}
	if (format[i] == 'c')
		ft_print_char(tab);
	if (format[i] == 's')
		ft_print_str(tab);
	if (format[i] == 'p')
		ft_print_pnt(tab);
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(tab);
	if (format[i] == 'u')
		ft_print_und(tab);
	if (format[i] == 'x')
		ft_print_hex(tab);
	if (format[i] == 'X')
		ft_print_hex_upper(tab);
	if (format[i] == '%')
		ft_print_perc(tab);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		return_value;
	int		i;
	t_print	*tab;

	return_value = 0;
	tab = malloc(sizeof(t_print));
	if (tab == NULL)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = -1;
	return_value = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i += ft_eval_format(tab, format, i + 1);
		else
			return_value += write(1, &format[i], 1);
	}
	va_end(tab->args);
	return_value += tab->total_len;
	free(tab);
	return (return_value);
}
