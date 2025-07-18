/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:08:51 by wilisson          #+#    #+#             */
/*   Updated: 2025/07/18 16:19:55 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	total;
	char	*ptr;

	if (!s1)
		return (NULL);
	total = ft_strlen(s1);
	ptr = malloc(total + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	{
		while (i < total)
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	ptr[total] = '\0';
	return (ptr);
}
