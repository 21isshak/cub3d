/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:27:05 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/06 12:46:04 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_texture_file(t_data *d, t_img *text, char *path)
{
	text->img = mlx_xpm_file_to_image(d->mlx, path, &text->w, &text->h);
	if (!text->img)
		print_error("Texture load failed");
	text->addr = mlx_get_data_addr(text->img,
			&text->bits_per_pixel, &text->line_length, &text->endian);
}

void	load_all_textures(t_data *d)
{
	load_texture_file(d, &d->tex.n_tex, d->tex.no);
	load_texture_file(d, &d->tex.s_tex, d->tex.so);
	load_texture_file(d, &d->tex.w_tex, d->tex.we);
	load_texture_file(d, &d->tex.e_tex, d->tex.ea);
}

int	get_tex_color(t_img *tex, int x, int y)
{
	char	*pixel;

	if (!tex || !tex->img || !tex->addr)
		return (0);
	if (x < 0 || y < 0 || x >= tex->w || y >= tex->h)
		return (0);
	pixel = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}
