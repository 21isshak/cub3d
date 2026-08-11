/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:09:59 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/07 15:33:07 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_walkable(char c)
{
	return (c == '0');
}

static int	is_border(t_map *m, int x, int y)
{
	return (y == 0 || y == m->height - 1 || x == 0 || x == m->width - 1);
}

static int	has_space_neighbor(t_map *m, int x, int y)
{
	return (m->grid[y - 1][x] == ' '
		|| m->grid[y + 1][x] == ' '
		|| m->grid[y][x - 1] == ' '
		|| m->grid[y][x + 1] == ' ');
}

int	is_map_closed(t_map *m)
{
	int	y;
	int	x;

	if (!m || !m->grid)
		return (0);
	if (m->height <= 0 || m->width <= 0)
		return (0);
	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (is_walkable(m->grid[y][x]))
			{
				if (is_border(m, x, y) || has_space_neighbor(m, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

// static int	check_row(char *row)
// {
// 	int	i;

// 	i = 0;
// 	while (row && row[i])
// 	{
// 		if (row[i] == '0')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	is_map_closed(t_map *m)
// {
// 	int	y;

// 	if (!m || !m->grid)
// 		return (0);
// 	if (!check_row(m->grid[0]))
// 		return (0);
// 	if (!check_row(m->grid[m->height - 1]))
// 		return (0);
// 	y = 0;
// 	while (y < m->height)
// 	{
// 		if (m->grid[y][0] == '0')
// 			return (0);
// 		if (m->grid[y][m->width - 1] == '0')
// 			return (0);
// 		y++;
// 	}
// 	return (1);
// }
