/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:06:33 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/07 18:06:35 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}
/*int main()
{
    // Test ft_calloc function
    int *ptr = (int *)ft_calloc(0, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    // Printing the initialized array
    printf("Initialized array:\n");
    int i = 0;
    while (i < 4)
    {
        printf("%d\n", ptr[i]);
        i++;
    }
    // Free allocated memory
    free(ptr);
    return 0;
}*/
