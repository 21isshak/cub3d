/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:52:38 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/06 15:00:29 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*int main() {
    char k;
    
    printf(": ");
    scanf("%c", &k);

    // Girilen karakteri büyük harfe dönüştürün
    int b = ft_toupper(k);

    // Sonucu yazdırın
    printf("büyük harfi: %c\n", b);

    return 0;
}*/
