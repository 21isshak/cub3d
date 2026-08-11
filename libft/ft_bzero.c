/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:06:31 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/23 14:31:30 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	a;
	char	*str;

	str = s;
	a = 0;
	while (a < n)
	{
		str[a] = 0;
		a++;
	}
}
/*
int main()
{
    char str[20] = "Hello, World!";
    char s[20] = "Hello, World!";
    printf("%s\n", s);
    ft_bzero(s, sizeof(s));
    printf("=>%s\n", s);
    printf("%s\n", str);
    bzero(str, sizeof(str));  // sets all bytes in str to 0
    printf("=>%s\n", str);   // output; empty string
    return 0;
}
*/
