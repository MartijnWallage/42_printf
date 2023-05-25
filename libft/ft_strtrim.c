/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:02:35 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/09 15:32:26 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	isinset(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static void	prep(char const *s1, char const *set, int *begin, int *end)
{
	*begin = 0;
	while (s1[*begin] && isinset(s1[*begin], set))
		(*begin)++;
	*end = *begin;
	while (s1[*end])
		(*end)++;
	while (s1[*end - 1] && isinset(s1[*end - 1], set))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		begin;
	int		end;
	int		i;

	prep(s1, set, &begin, &end);
	if (begin >= end)
		trim = malloc(1);
	else
		trim = malloc(end - begin + 1);
	if (trim == NULL)
		return (NULL);
	i = begin;
	while (i < end)
	{
		trim[i - begin] = s1[i];
		i++;
	}
	trim[i - begin] = '\0';
	return (trim);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "!** bb **!"; 
	char	*set = "!* ";
	char	*trim;

	trim = ft_strtrim(str, set);
	printf("%saaa\n", trim);
	free(trim);
	return (0);
}*/
