/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:36:41 by wilisson          #+#    #+#             */
/*   Updated: 2025/07/12 18:27:00 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *poi, int c, size_t len)
{
	size_t i;

	i = 0;
	if (poi == NULL)
	{
		return(NULL);
	}
	unsigned char *ptr;
	ptr = (unsigned char *)poi;

	while (i < len && ptr[i] != '\0')
	{
		ptr[i] = c;
		i++;
	}
	return (poi);
}

int main()
{
	char *dimi = "hi my name is dimi";
 	ft_memset(dimi, 'c', 30);	
}