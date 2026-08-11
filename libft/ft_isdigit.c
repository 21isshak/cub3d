/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:06:54 by iskaraag          #+#    #+#             */
/*   Updated: 2024/02/28 16:06:55 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}
/*#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc != 2)
        return 0;

    char *a = argv[1];
    int b = ft_isdigit(*a);

    printf("%d\n", b);

    return 0;
}*/
