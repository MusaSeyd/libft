/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:17:51 by fcelesti          #+#    #+#             */
/*   Updated: 2021/10/20 15:17:54 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	j = i;
	while (i + 1 < dstsize && src[i - j])
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < dstsize)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	len_src;
// 	size_t	len_dst;
// 	size_t	i;

// 	len_dst = ft_strlen(dst);
// 	len_src = ft_strlen(src);
// 	i = 0;
// 	if (dstsize == 0)
// 		return (len_src);
// 	if (len_dst >= dstsize)
// 		len_src += dstsize;
// 	else
// 		len_src += len_dst;
// 	while (src[i])
// 	{
// 		// if (i > sizeof )
// 		dst[len_dst] = src[i];
// 		len_dst++;
// 		i++;
// 	}
// 	dst[len_dst] = '\0';
// 	return (len_dst);
// }

// int main ()
// {
// 	char	dest[14] = "a";
// 	char	dest2[14] = "a";
// 	size_t	res;
// 	size_t	res2;

// 	res = ft_strlcat(dest, "lorem ipsum dolor sit amet", 15);
// 	// res2 = strlcat(dest2, "lorem ipsum dolor sit amet", 14);
// 	printf("%lu\n", res);
// 	printf("%s\n", dest);
// 	// printf("%lu\n", res2);
// 	// printf("%s\n", dest2);
// }