/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:07:39 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/25 16:05:43 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_init_tab(t_print *tab)
{
	tab->width		= 0;
	tab->precision	= 0;
	tab->zero		= 0;
	tab->point		= 0;
	tab->dash		= 0;
	tab->total_len	= 0;
	tab->sign		= 0;
	tab->is_zero	= 0;
	tab->percent	= 0;
	tab->space		= 0;
}

int	is_in_set(const char c, const char *set)
{
	while (*set != c)
		set++;
	return (*set);
}

void	ft_print_int(t_print *tab)
{
	int		nb;
	int		len;
	int		div;
	char	c;

	nb = va_arg(tab->args, int);
	len = 1;
	div = 1;
	while (nb / div > 9)
	{
		div *= 10;
		len++;
	}
	tab->total_len += len;
	while (len--)
	{
		c = nb / div + '0';
		write(1, &c, 1);
		nb %= 10;
		div /= 10;
	}
}

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->total_len += write(1, &c, 1);
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
	if (format[i] == 'd')
		ft_print_int(tab);
	if (format[i] == 'c')
		ft_print_char(tab);
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
