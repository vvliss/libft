/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:46:34 by wilisson          #+#    #+#             */
/*   Updated: 2025/07/19 15:55:35 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;
	char *tmp_ptr;
	size_t len_1;
	size_t len_2;
	
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2)); //bc when one string is NULL, you should treat it as empty (but still allocate new memory)
	if (!s2)
		return (ft_strdup(s1));
	ptr = malloc(len_1 + len_2 + 1); //bc strlen gives just the character count before '\0'
	if (!ptr)
		return (NULL);
	*tmp_ptr = ptr;
	while (*s1)
	{
		*tmp_ptr = *s1;
		tmp_ptr++;
		s1++;
	}
	while (*s2)
	{
		*tmp_ptr = *s2;
		tmp_ptr++;
		s2++;	
	}
	*tmp_ptr = '\0';
	return (ptr);
}