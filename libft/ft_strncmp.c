/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:49:23 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/06 16:49:26 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	t;
	size_t	f;

	t = 0;
	f = 0;
	while (t < n && s1[t] != '\0' && s2[f] != '\0')
	{
		if (s1[t] != s2[f])
			return (s1[t] - s2[f]);
		t++;
		f++;
	}
	if (t < n)
		return (s1[t] - s2[f]);
	return (0);
}
/*int main()
{
    char a[] = "hello";
    char b[] = "helloo";
    
    int c = ft_strncmp(a, b, 6);
    printf("%d\n", c);
}*/
