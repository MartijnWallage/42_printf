/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:02 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/27 18:45:55 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		total_len;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
}				t_print;

int				ft_printf(const char *format, ...);
int				ft_eval_format(t_print *tab, const char *format, int i);
void			ft_init_tab(t_print *tab);
/* Conversions */
void			ft_print_char(t_print *tab);
void			ft_print_str(t_print *tab);
void			ft_print_pnt(t_print *tab);
void			ft_print_int(t_print *tab);
void			ft_print_und(t_print *tab);
void			ft_print_hex(t_print *tab);
void			ft_print_hex_upper(t_print *tab);
void			ft_print_perc(t_print *tab);
/* Print conversions */
unsigned int	ft_putstr(char *str);
unsigned int	ft_putnbr_base(ssize_t nbr, char *base);
/* Utility functions */
unsigned int	ft_strlen(const char *str);
size_t			ft_abs(ssize_t nbr);
int				is_in_set(const char c, const char *set);

#endif
