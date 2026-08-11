/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:10:35 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/07 15:24:42 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_texture_paths(t_tex *tex)
{
	if (!tex)
		return ;
	if (tex->no)
	{
		free(tex->no);
		tex->no = NULL;
	}
	if (tex->so)
	{
		free(tex->so);
		tex->so = NULL;
	}
	if (tex->we)
	{
		free(tex->we);
		tex->we = NULL;
	}
	if (tex->ea)
	{
		free(tex->ea);
		tex->ea = NULL;
	}
}
