/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:03:21 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/06 15:03:22 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*int main() {
    char k;
    
    printf(": ");
    scanf("%c", &k);

    // Girilen karakteri büyük harfe dönüştürün
    int b = ft_tolower(k);

    // Sonucu yazdırın
    printf("kucuk harfi: %c\n", b);

    return 0;
}*/
