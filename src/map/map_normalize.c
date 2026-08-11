/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:09:24 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/07 15:15:44 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	max_width(char **raw)
{
	int	i;
	int	w;
	int	len;

	w = 0;
	i = 0;
	while (raw && raw[i])
	{
		len = ft_strlen(raw[i]);
		if (len > w)
			w = len;
		i++;
	}
	return (w);
}

static void	normalize_row(char *dest, char *src, int width)
{
	int	x;
	int	len;

	len = ft_strlen(src);
	x = 0;
	while (x < width)
	{
		if (x < len && src[x] != '\n')
			dest[x] = src[x];
		else
			dest[x] = ' ';
		x++;
	}
	dest[width] = '\0';
}

char	**normalize_map(char **raw)
{
	int		h;
	int		w;
	char	**out;
	int		y;

	h = 0;
	while (raw && raw[h])
		h++;
	w = max_width(raw);
	out = malloc(sizeof(char *) * (h + 1));
	if (!out)
		print_error("Malloc failed");
	y = 0;
	while (y < h)
	{
		out[y] = malloc(w + 1);
		if (!out[y])
			print_error("Malloc failed");
		normalize_row(out[y], raw[y], w);
		y++;
	}
	out[h] = NULL;
	return (out);
}
