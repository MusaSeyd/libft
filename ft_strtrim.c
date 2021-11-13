/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:27:56 by fcelesti          #+#    #+#             */
/*   Updated: 2021/10/23 16:27:58 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lens1;
	size_t	j;

	if (!s1 || !set)
		return (0);
	j = 0;
	lens1 = ft_strlen(s1);
	while (s1[j] && ft_strchr(set, s1[j]))
		j++;
	if (s1[j] == '\0')
		return (ft_strdup(""));
	while (lens1 - 1 >= 0 && ft_strchr(set, s1[lens1 - 1]))
		lens1--;
	return (ft_substr(s1, j, lens1 - j));
}
