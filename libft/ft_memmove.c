/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:24:16 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/01 16:24:17 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (src > dest)
		dest = ft_memcpy(dest, src, n);
	else
	{
		d = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
/*int main() {
    char str1[10] = "Hello";
    char str2[10] = "World";
    char str3[10] = "Hello";
    char str4[10] = "World";

    // str2'nin içeriği, str1'in içeriğine kopyalanıyor.
    memmove(str2, str1, 5);
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
    ft_memmove(str4, str3, 5);
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}*/
