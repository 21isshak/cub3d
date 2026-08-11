/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:04:35 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/04 17:04:19 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_cub(char *file, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Cannot open file");
	line = get_next_line(fd);
	while (line)
	{
		parse_texture_line(&data->tex, line);
		parse_color_line(data, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Cannot open file");
	data->map = parse_map_from_fd(fd);
	close(fd);
}
