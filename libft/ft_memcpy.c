/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:57:57 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/01 15:57:59 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((unsigned char *)dest)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dest);
}
/*
int main() {
    char source[] = "Hello, World!";
    char destination[5];
    char s[] = "Hello, World!";
    char d[5];

    
    memcpy(destination, source, strlen(source) + 1);  
    printf("%s\n", destination); 
    ft_memcpy(d , s, strlen(s) + 1);
    printf("%s\n", d);

    return 0;
}*/
