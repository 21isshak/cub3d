/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:30:57 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/05 16:30:59 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (dst[a] != '\0' && a < size)
		a++;
	while (src[b] != '\0' && (a + b + 1) < size)
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a < size)
		dst[a + b] = '\0';
	return (a + ft_strlen(src));
}
/*int main()
{
	char a[] = "alooooooo";
	char b[] = "merhaba";
	printf("%ld\n", ft_strlcat(a, b, 3));
	printf("%s\n", a);
	return (0);
}*/
