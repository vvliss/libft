/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:04:28 by wilisson          #+#    #+#             */
/*   Updated: 2025/07/20 18:43:39 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Counts how many words (substrings) exist in s separated by c
static size_t	counting_substrings(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			cnt++;
			while (*s && *s != c) // skips all c delimiters (handles leading/multiple delimiters)
				s++;
		}
	}
	return (cnt);
}
// Frees all allocated memory if an error occurs
static char	**free_all(char **split, size_t i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	split = malloc((counting_substrings(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		if (!s[start])
			break ;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		split[i] = malloc((end - start + 1) * sizeof(char));
		if (!split[i])
			return (free_all(split, i));
		ft_strlcpy(split[i], &s[start], end - start + 1);
		i++;
		start = end;
	}
	split[i] = NULL;
	return (split);
}
