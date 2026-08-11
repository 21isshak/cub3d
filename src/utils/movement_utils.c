/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:33:13 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/10 16:40:09 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_walkable_cell(char c)
{
	return (c == '0');
}

int	can_move(t_map *map, double new_x, double new_y)
{
	int	mx;
	int	my;

	mx = (int)new_x;
	my = (int)new_y;
	if (my < 0 || my >= map->height || mx < 0 || mx >= map->width)
		return (0);
	return (is_walkable_cell(map->grid[my][mx]));
}
