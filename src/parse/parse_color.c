/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:06:07 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/04 17:03:29 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_rgb(t_rgb *c, char *line)
{
	char	**p;

	p = ft_split(line, ',');
	if (!p || !p[0] || !p[1] || !p[2])
	{
		free_split(p);
		return (1);
	}
	c->r = ft_atoi(p[0]);
	c->g = ft_atoi(p[1]);
	c->b = ft_atoi(p[2]);
	free_split(p);
	if (c->r < 0 || c->r > 255)
		return (1);
	if (c->g < 0 || c->g > 255)
		return (1);
	if (c->b < 0 || c->b > 255)
		return (1);
	return (0);
}

void	parse_color_line(t_data *data, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "F ", 2))
	{
		if (parse_rgb(&data->floor, line + 2))
			print_error("Invalid floor color");
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (parse_rgb(&data->ceilc, line + 2))
			print_error("Invalid ceiling color");
	}
}
