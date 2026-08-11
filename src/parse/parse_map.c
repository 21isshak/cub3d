/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:07:32 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/07 15:33:35 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**map_add_line(char **map, char *line)
{
	int		i;
	char	**new;

	i = 0;
	while (map && map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		print_error("Malloc failed");
	i = 0;
	while (map && map[i])
	{
		new[i] = map[i];
		i++;
	}
	new[i] = ft_strdup(line);
	new[i + 1] = NULL;
	free(map);
	return (new);
}

static int	handle_before_map(char ***map, char *line, int *started)
{
	if (is_map_line(line))
	{
		*started = 1;
		*map = map_add_line(*map, line);
	}
	return (0);
}

static void	handle_after_map(char ***map, char *line)
{
	if (!is_map_line(line))
	{
		free(line);
		print_error("Invalid line after map started");
	}
	*map = map_add_line(*map, line);
}

char	**collect_map(int fd)
{
	char	*line;
	char	**map;
	int		started;

	map = NULL;
	started = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!started)
			handle_before_map(&map, line, &started);
		else
			handle_after_map(&map, line);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

t_map	parse_map_from_fd(int fd)
{
	t_map	m;
	char	**raw;
	int		player_count;

	raw = collect_map(fd);
	m.grid = normalize_map(raw);
	free_split(raw);
	m.height = 0;
	while (m.grid && m.grid[m.height])
		m.height++;
	if (m.height == 0)
		print_error("Map is empty or invalid");
	m.width = ft_strlen(m.grid[0]);
	player_count = find_player(&m);
	if (player_count == 0)
		print_error("Player not found");
	if (player_count > 1)
		print_error("Multiple players found in map");
	if (!is_map_closed(&m))
		print_error("Map not closed");
	return (m);
}
