/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:05:40 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/06 12:45:41 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	assign_tex(t_tex *t, char *line, char *id)
{
	size_t	len;
	char	*path;
	char	*trimmed;

	len = ft_strlen(id);
	path = line + len;
	while (*path == ' ' || *path == '\t')
		path++;
	trimmed = ft_strtrim(path, " \t\n\r");
	if (!ft_strncmp(line, "NO ", len))
		t->no = trimmed;
	else if (!ft_strncmp(line, "SO ", len))
		t->so = trimmed;
	else if (!ft_strncmp(line, "WE ", len))
		t->we = trimmed;
	else if (!ft_strncmp(line, "EA ", len))
		t->ea = trimmed;
}

/*
** parse_texture_line
** Accepts lines that start with NO/SO/WE/EA.
*/
void	parse_texture_line(t_tex *tex, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		assign_tex(tex, line, "NO ");
	else if (!ft_strncmp(line, "SO ", 3))
		assign_tex(tex, line, "SO ");
	else if (!ft_strncmp(line, "WE ", 3))
		assign_tex(tex, line, "WE ");
	else if (!ft_strncmp(line, "EA ", 3))
		assign_tex(tex, line, "EA ");
}
