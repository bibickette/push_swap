/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_pushswap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:22:20 by phwang            #+#    #+#             */
/*   Updated: 2024/02/18 16:18:08 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIBFT/libft.h"
#include "../LIBFT/ft_printf/ft_printf.h"

static int	countwords(char const *s, char c)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i + 1])
	{
		if ((s[i] == c && s[i + 1] != c)
			|| (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static char	**fill_fill(char **tab, int pos, char const **s, int j)
{
	int	n;

	n = 0;
	while (n < j)
	{
		tab[pos][n] = **s;
		n++;
		(*s)++;
	}
	tab[pos][n] = '\0';
	return (tab);
}

static char	**fill_tab(char **tab, int pos, char const *s, char sep)
{
	int	j;

	j = 0;
	while (*s == sep)
		s++;
	while (*(s + j) != sep && *(s + j) != '\0')
		j++;
	if (j == 0)
		return (tab);
	tab[pos] = malloc((j + 1) * sizeof(char));
	if (!tab[pos])
	{
		tab[pos] = NULL;
		return (tab);
	}
	tab = fill_fill(tab, pos, &s, j);
	if (*s == '\0')
		return (tab);
	return (fill_tab(tab, pos + 1, s, sep));
}

char	**split(char const *s, char c)
{
	char	**ntab;
	int		size;
	int		pos;

	pos = 1;
	size = countwords(s, c) + 1;
	ntab = malloc((size + 1) * sizeof(char *));
	if (!ntab)
		return (NULL);
	if (size == 0)
	{
		ntab[0] = NULL;
		return (ntab);
	}
	ntab[0] = '\0';
	ntab = fill_tab(ntab, pos, s, c);
	ntab[size] = '\0';
	return (ntab);
}
