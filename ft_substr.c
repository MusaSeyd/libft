/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:47:05 by fcelesti          #+#    #+#             */
/*   Updated: 2021/10/23 11:47:13 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*sub_str;

	sub_str = NULL;
	if (s != NULL)
	{
		length = ft_strlen(s);
		if (len > length)
			len = length;
		if (start > length)
			start = (unsigned int)length;
		if (start + len > length)
			len = length - start;
		sub_str = (char *)malloc(sizeof(char) * len + 1);
		if (sub_str != NULL)
		{
			ft_memmove(sub_str, s + start, len);
			sub_str[len] = '\0';
		}
	}
	return (sub_str);
}
