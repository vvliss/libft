/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:13:14 by wilisson          #+#    #+#             */
/*   Updated: 2025/07/12 18:29:41 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// #include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	pos;

	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}

// int main(void)
// {
//     const char* test = "Som3thing m0re,, cr3ative?";
//     size_t leng = ft_strlen(test);

//     printf("%zu\n", leng);

//     return (0);
// }