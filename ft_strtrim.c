/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:21:32 by wilisson          #+#    #+#             */
/*   Updated: 2025/07/20 12:58:03 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    char *trimmed;

    if (!s1 || !set)
        return NULL;

    	// Find start (first non-set char)
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;

    	// Find end (last non-set char)
    end = ft_strlen(s1);
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;

    	// Allocate and copy
    trimmed = malloc(end - start + 1);
    if (!trimmed)
        return NULL;
    ft_strlcpy(trimmed, s1 + start, end - start + 1);
    return trimmed;
}