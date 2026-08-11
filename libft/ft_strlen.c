/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:41:13 by iskaraag          #+#    #+#             */
/*   Updated: 2023/11/27 19:02:05 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}
/*int main()
{
    char *str;
    str = "heyy";

    printf("%d", ft_strlen(str));
    return(0);
}*/
