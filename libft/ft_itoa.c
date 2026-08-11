/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:05:57 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/11 14:05:58 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	len_nmbr(int n)
{
	unsigned int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static unsigned int	abs_nmbr(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static char	*new_strng(size_t n)
{
	char	*strng;

	strng = (char *)malloc(sizeof(char) * (n + 1));
	if (strng == NULL)
		return (NULL);
	return (strng);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				sign;
	int				len;
	char			*str;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = len_nmbr(n);
	str = new_strng(len);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	nb = abs_nmbr(n);
	while (len >= 1)
	{
		len--;
		str[len] = '0' + nb % 10;
		nb /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
/*
int main()
{
    int num = -2147483648;
    char *result = ft_itoa(num);
    if (result != NULL)
    {
        printf(":%s\n", result);
        free(result);
    }
    else
        printf("allocation failed\n");
    return 0;
}
*/
