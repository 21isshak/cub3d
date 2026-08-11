/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:36:11 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/07 19:36:13 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		a;
	size_t		b;
	char		*result;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		result[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		result[a] = s2[b];
		a++;
		b++;
	}
	result[a] = '\0';
	return (result);
}
/*int main()
{
   
    char *s = "dada";
    char *k = "baba";
    char *r = ft_strjoin(s, k);

    printf("%s", r);
    free(r);
    return 0;
}*/
