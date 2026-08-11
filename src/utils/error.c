/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:10:23 by iskaraag          #+#    #+#             */
/*   Updated: 2025/11/20 19:10:31 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_error(char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}
