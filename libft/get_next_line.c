/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:52:52 by iskaraag          #+#    #+#             */
/*   Updated: 2025/11/11 15:22:56 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_getline(int fd, char **readen, int first)
{
	int	i;

	if (first == 1)
	{
		if (*readen && first == 1)
			return (ft_strlenn(*readen));
		*readen = malloc((long int)BUFFER_SIZE + 1);
		if (!(*readen))
		{
			*readen = NULL;
			return (0);
		}
	}
	i = read(fd, *readen, BUFFER_SIZE);
	if (i >= 0)
	{
		(*readen)[i] = '\0';
		i = ft_strlenn(*readen);
	}
	else
	{
		free(*readen);
		(*readen) = NULL;
	}
	return (i);
}

char	*ft_errorfree(char **s1, char *s2)
{
	if ((*s1))
		free((*s1));
	(*s1) = NULL;
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*redded;
	int			i;
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = f_getline(fd, &redded, 1);
	while (i > 0)
	{
		res = ft_strjoin_gnl(&res, redded, i);
		if (!res)
			return (ft_errorfree(&redded, NULL));
		if (redded[i - 1] == 10)
		{
			if (redded[i] == 0)
				break ;
			redded = ft_cshift(redded, i);
			return (res);
		}
		i = f_getline(fd, &redded, 0);
	}
	return (ft_errorfree(&redded, res));
}
