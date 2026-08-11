/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:22:49 by iskaraag          #+#    #+#             */
/*   Updated: 2024/02/28 16:22:50 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t num)
{
	size_t			a;
	unsigned char	*str;

	str = dest;
	a = 0;
	while (a < num)
	{
		str[a] = value;
		a++;
	}
	return (dest);
}
/*
int main()
{
   	char str[10];
   	char s[10];
   	ft_memset(str, 'A', 10);
	printf("%s\n", str);
	memset(s, 'A', 10);
	printf("%s\n", s);
	return 0;
}
*/