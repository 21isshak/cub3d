/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:07:19 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/07 14:33:08 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map_line(char *l)
{
	int	i;
	int	has_tile_char;

	i = 0;
	has_tile_char = 0;
	if (!l)
		return (0);
	while (l[i])
	{
		if (l[i] != ' ' && l[i] != '1' && l[i] != '0'
			&& l[i] != 'N' && l[i] != 'S' && l[i] != 'E'
			&& l[i] != 'W' && l[i] != '\n')
			return (0);
		if (l[i] == '0' || l[i] == '1' || l[i] == 'N'
			|| l[i] == 'S' || l[i] == 'E' || l[i] == 'W')
			has_tile_char = 1;
		i++;
	}
	return (has_tile_char);
}
