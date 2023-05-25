/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:13:16 by mwallage          #+#    #+#             */
/*   Updated: 2023/05/10 17:18:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_wordlen(const char *s, const char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	size++;
	return (size);
}

static size_t	count_words(const char *s, const char c)
{
	int		wait;
	size_t	counter;

	wait = 1;
	counter = 0;
	while (*s)
	{
		if (wait && *s != c)
			counter++;
		wait = (*s == c);
		s++;
	}
	return (counter);
}

static void	fill_str(char *tabs, const char *s, size_t wordlen)
{
	size_t	i;

	i = 0;
	while (i < wordlen - 1)
	{
		tabs[i] = *s;
		i++;
		s++;
	}
	tabs[i] = '\0';
}

static void	*free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	wordlen;
	size_t	i;

	words = count_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		wordlen = ft_wordlen(s, c);
		tab[i] = malloc(wordlen);
		if (tab[i] == NULL)
			return (free_tab(tab));
		fill_str(tab[i], s, wordlen);
		s += wordlen;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*s = "\0aa\0bbb";
	char	c = '\0';
	char	**tab;
	int		i;

	if (argc != 3)
		return (1);
//	s = argv[1];
//	c = argv[2][0];
	tab = ft_split(s, c);
	i = 0;
	while (i <= count_words(s, c))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	while (i <= count_words(s, c))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/