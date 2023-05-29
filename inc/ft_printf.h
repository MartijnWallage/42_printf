/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:02 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/29 18:10:06 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>

#define DEC			"0123456789"
#define HEX_LOWER	"0123456789abcdef"
#define HEX_UPPER	"0123456789ABCDEF"

typedef struct s_print
{
	va_list	args;
	int		hash;
	int		width;
	int		precision;
	char	padding;
	int		point;
	int		dash;
	int		len;
	int		sign;
	int		space;
	int		neg;
}				t_print;

int				ft_printf(const char *format, ...);
int				ft_eval_format(t_print *tab, const char *format, int i);
void			ft_init_tab(t_print *tab);
/* Read modifiers*/
int				read_flags(t_print *tab, const char *format, int i);
int				read_width(t_print *tab, const char *format, int i);
int				read_precision(t_print *tab, const char *format, int i);
/* Conversions */
void			ft_print_char(t_print *tab);
void			ft_print_str(t_print *tab);
void			ft_print_pnt(t_print *tab);
void			ft_print_int(t_print *tab);
void			ft_print_uns(t_print *tab);
void			ft_print_hex(t_print *tab);
void			ft_print_hex_upper(t_print *tab);
void			ft_print_perc(t_print *tab);
/* Print conversions */
unsigned int	ft_putstr(char *str, int strlen);
unsigned int	ft_putnbr_base(ssize_t nbr, char *base);
int				put_padding(t_print *tab, char c, int len);
int				put_sign_or_space(t_print *tab);
/* Utility functions */
unsigned int	ft_strlen(const char *str);
size_t			ft_abs(ssize_t nbr);
int				is_in_set(const char c, const char *set);
int				ft_atoi_start_to_end(const char *str, int start, int end);
unsigned int	ft_numdigits(size_t nbr, unsigned int baselen);
int				ft_min(int a, int b);
int				ft_max(int a, int b);

#endif
