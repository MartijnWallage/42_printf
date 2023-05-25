/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:02 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/25 16:04:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_print                       
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

int		ft_printf(const char *format, ...);
int		ft_eval_format(t_print *tab, const char *format, int i);
int		is_in_set(const char c, const char *set);
void	ft_init_tab(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_char(t_print *tab);

#endif
