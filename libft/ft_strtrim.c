/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:20:31 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/07 21:20:32 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, const char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_checkset(s1[start], set) != 0)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_checkset(s1[end - 1], set) != 0)
		end--;
	len = end - start;
	trimmed = (char *)malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	return (trimmed);
}
/*int main()
{
	char	*str = "a a a a wdf rawd f rawdf rga a a a";
	char	*a = " a";
	char	*c = ft_strtrim(str, a);
	printf(":%s", c);
	free (c);
	return (0);
}*/
