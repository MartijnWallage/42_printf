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
	tab->hash = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->dash = 0;
	tab->total_len = 0;
	tab->sign = 0;
	tab->space = 0;
	tab->neg = 0;
}

/*  %[$][flags][width][.precision][length modifier]conversion */
int	ft_eval_format(t_print *tab, const char *format, int i)
{
	i = read_flags(tab, format, i);
	i = read_width(tab, format, i);
	i = read_precision(tab, format, i);
	if (format[i] == 'c')
		ft_print_char(tab);
	else if (format[i] == 's')
		ft_print_str(tab);
	else if (format[i] == 'p')
		ft_print_pnt(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(tab);
	else if (format[i] == 'u')
		ft_print_und(tab);
	else if (format[i] == 'x')
		ft_print_hex(tab);
	else if (format[i] == 'X')
		ft_print_hex_upper(tab);
	else if (format[i] == '%')
		ft_print_perc(tab);
	return (i);
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
	va_start(tab->args, format);
	i = -1;
	while (format[++i])
	{
		ft_init_tab(tab);
		if (format[i] == '%')
		{
			i = ft_eval_format(tab, format, i + 1);
			return_value += tab->total_len;
		}
		else
			return_value += write(1, &format[i], 1);
	}
	va_end(tab->args);
	free(tab);
	return (return_value);
}
