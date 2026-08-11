/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:09:42 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/07 15:34:05 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	handle_player_tile(t_map *m, int x, int y, int *count)
{
	if (*count == 0)
	{
		m->player.x = x;
		m->player.y = y;
		m->player.dir = m->grid[y][x];
	}
	m->grid[y][x] = '0';
	(*count)++;
}

int	find_player(t_map *m)
{
	int	y;
	int	x;
	int	count;

	if (!m || !m->grid)
		return (0);
	count = 0;
	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (m->grid[y][x] == 'N' || m->grid[y][x] == 'S'
				|| m->grid[y][x] == 'E' || m->grid[y][x] == 'W')
				handle_player_tile(m, x, y, &count);
			x++;
		}
		y++;
	}
	return (count);
}
