/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:06:11 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/11 14:06:12 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*new;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
char increment_char(unsigned int index, char c)
{
	(void)index;
    return c + 1;
}

int main()
{
    const char *input = "Hello";

    char *result = ft_strmapi(input, &increment_char);

    if (result == NULL)
    {
        printf("NOPE.\n");
        return (1);
    }

    printf("inputstr: %s\n", input);
    printf("resultstr: %s\n", result);

    free(result);
    return 0;
}
*/
