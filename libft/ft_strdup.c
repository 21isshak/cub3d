/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:50:09 by iskaraag          #+#    #+#             */
/*   Updated: 2024/02/27 13:43:27 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		ln;
	size_t		i;
	char		*dest;

	ln = 0;
	while (src[ln] != '\0')
	{
		ln++;
	}
	dest = (char *)malloc(sizeof(char) * (ln + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
	char *s1;
	char *s2;
	char *dest1;
	char *dest2;
	
	s1 = "asdsa";
	dest1 = strdup(s1);
	s2 = "asdsa";
	dest2 = ft_strdup(s2);
	
		
	printf("Orgnal: %s\n", s1);
    printf("Duplicated: %s\n", dest1);
    printf("Orgnal: %s\n", s2);
    printf("FT_Duplicated: %s\n", dest2);
    	    	
    free(dest1);
    free(dest2);
    return (0);
}
*/
