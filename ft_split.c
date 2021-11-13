/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:24:15 by fcelesti          #+#    #+#             */
/*   Updated: 2021/10/24 19:24:16 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **massiv)
{
	size_t	j;

	j = 0;
	while (massiv[j] != NULL)
	{
		free(massiv[j]);
		j++;
	}
	free(massiv);
}

static char	*ft_copystr(char *s, char c)
{
	size_t	i;
	char	*copystr;

	i = 0;
	copystr = NULL;
	while (s[i] != c && s[i])
		i++;
	copystr = (char *)malloc(sizeof(char) * (i + 1));
	if (!copystr)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		copystr[i] = s[i];
		i++;
	}
	copystr[i] = '\0';
	return (copystr);
}

static char	**ft_spliter(char **massiv, char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		massiv[j] = NULL;
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			massiv[j] = ft_copystr((char *)s + i, c);
			if (!massiv[j])
			{
				ft_free(massiv);
				return (0);
			}
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	massiv[j] = NULL;
	return (massiv);
}

static int	ft_countwords(char	*s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**massiv;

	if (!s)
		return (0);
	massiv = NULL;
	count = ft_countwords((char *)s, c);
	massiv = (char **)malloc(sizeof(char *) * (count + 1));
	if (!massiv)
		return (0);
	massiv = ft_spliter(massiv, (char *)s, c);
	if (!massiv)
		return (0);
	return (massiv);
}

int main ()
{
	char **arr = ft_split("lorem ipsum privet salam", ' ');
	int i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return
}