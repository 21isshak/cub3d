/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:06:24 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/11 14:06:25 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
/*
void example_function(unsigned int index, char *character)
{
	(void)index;
    if (*character >= 'a' && *character <= 'z')
        *character -= 32; 
}
int main()
{
    char str[] = "hello42merhaba";

    printf("original string: %s\n", str);
    ft_striteri(str, &example_function);
    printf("new string: %s\n", str);

    return 0;
}
*/
