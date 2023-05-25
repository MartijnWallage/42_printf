/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:30:42 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/09 18:01:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d > s && d < s + n)
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

/*
#include <stdio.h>
int main() 
{
    char *src = "Hello, World!";
    char dest[14];
    
    ft_memmove(dest, src, 7);
    printf("%s\n", dest);
    return (0);
}*/
