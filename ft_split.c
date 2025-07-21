/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:04:28 by wilisson          #+#    #+#             */
/*   Updated: 2025/07/21 16:26:42 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counting_substrings(char const *s, char c)
{
	size_t	cont;

	cont = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			cont++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cont);
}

static void	free_all(char **split)
{
	size_t i;

	i = 0;
	if (split == NULL) //we checking whether the "list" itself exists
		return ;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	size_t sub_len;
	size_t i;
	char **split;
	
	i = 0;
	split = (char **)malloc((counting_substrings(s, c) + 1) * sizeof(char *)); //split will hold the address of an array of strings (char *)
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			sub_len = ft_strchr(s, c) - s;
			if (!ft_strchr(s, c))
				sub_len = ft_strlen(s);
			split[i] = ft_substr(s, 0, sub_len);
			if (!split[i])
				return (free_all(split), NULL);
			i++;
			s = s + sub_len; //skipping (changing place) to the end of the currently worked on sub
		}
	}
	return (split[i] = NULL, split);
}

// int main (void)
// {
// 	char *str = "I need to be split    by           eachspace";
// 	char c = ' ';

// 	char **res = ft_split(str, c);
// 	for (int i = 0; res[i] != NULL;)
// 	{
// 		printf("\n%s\n", res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// }