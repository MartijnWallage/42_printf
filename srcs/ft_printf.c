#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
  int   return_value;
  t_print *tab;
  
  return_value = 0;
  tab = malloc(sizeof(t_print));
  if (tab == NULL)
    return (0);
  init_tab(tab);
  return (return_value);
}
