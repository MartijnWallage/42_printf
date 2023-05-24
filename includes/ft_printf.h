#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

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

int ft_printf(const char *format, ...);

#endif
