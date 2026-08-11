/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:21:22 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/06 18:21:23 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (((unsigned char *)s)[a] == (unsigned char)c)
			return ((void *)&((unsigned char *)s)[a]);
		a++;
	}
	return (NULL);
}
/*int main()
{
    const char *s = "Merhaba, Dunya!";
    char *p;

    p = ft_memchr(s, 'D', 20);
    if (p != NULL)
        printf("bulunduğu pozisyon: %ld\n", p - s);
    else 
        printf("bulunamadı.\n");
    
    return 0;
}*/
