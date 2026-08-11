/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:12:02 by iskaraag          #+#    #+#             */
/*   Updated: 2024/02/28 16:12:06 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	return (0);
}
/*#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc != 2)
        return 0;

    char *a = argv[1];
    int b = ft_isalnum(*a);

    printf("%d\n", b);

    return 0;
}*/
