/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:47:54 by iskaraag          #+#    #+#             */
/*   Updated: 2024/03/08 15:47:56 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	count_words(char const *string, char c)
{
	int	count;
	int	inword;

	count = 0;
	inword = 0;
	while (*string != '\0')
	{
		if (*string == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			count++;
		}
		string++;
	}
	return (count);
}

static char	*putword(char *word, char const *s, int i, int word_len)
{
	while (word_len > 0)
	{
		*word = s[i - word_len];
		word++;
		word_len--;
	}
	*word = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (s2 == NULL)
			return (free_array(s2, word));
		putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (s == NULL)
		return (0);
	num_words = count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (s2 == NULL)
		return (0);
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}
/*static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static char	*f_strtok(char *str, const char *delim)
{
	static char	*next_token = NULL;
	char		*token_start;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	while (*next_token != '\0' && ft_strchr(delim, *next_token) != NULL)
		next_token++;
	if (*next_token == '\0')
		return (NULL);
	token_start = next_token;
	while (*next_token != '\0' && ft_strchr(delim, *next_token) == NULL)
		next_token++;
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	return (token_start);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**v;
	int		nw;
	int		i;

	if (s == NULL)
		return (0);
	str = ft_strdup(s);
	if (f_strtok(str, &c) == 0)
		return (NULL);
	nw = 1;
	while (f_strtok(NULL, &c) != 0)
		nw += 1;
	ft_strcpy(str, s);
	v = malloc((nw + 1) * sizeof(char *));
	if (v == NULL)
		return (free (str), NULL);
	v[0] = ft_strdup(f_strtok(str, &c));
	i = 1;
	while (i != nw)
	{
		v[i] = ft_strdup(f_strtok(NULL, &c));
		if (v[i] == NULL)
		{
			free_array(v, i);
			return (free (str), NULL);
		}
		i++;
	}
	v[i] = NULL;
	return (free (str), v);
}*/
/*#include <stdio.h>
int main()
{
    char *inp = "hey 42,meraba ben ishak, ";
    char delimiter = ' ';
    char **result = ft_split(inp, delimiter);
    int i;
    int j;
    if (result == NULL)
    {
        printf("nope\n");
        return (0);
    }
    printf("strnigs:\n");
    i = 0;
    while (result[i] != NULL)
    {
    	printf("%s\n", result[i]);
    	i++;
    }
    j = i;
    printf("%d\n", j);
    i = 0;
    while (result[i] != NULL)
    {
    	free (result[i]);
    	i++;
    }
    free(result);
    return 0;
}*/
