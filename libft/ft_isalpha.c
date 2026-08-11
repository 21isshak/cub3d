/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:03:16 by iskaraag          #+#    #+#             */
/*   Updated: 2024/02/28 16:03:19 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	return (0);
}
/*#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc != 2)
        return 0;

    char *a = argv[1];
    int b = ft_isalpha(*a);

    printf("%d\n", b);

    return 0;
}*/
