/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:55:47 by fcelesti          #+#    #+#             */
/*   Updated: 2021/10/26 18:55:48 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_numtochar(long n, char	*str, size_t count)
{
	int		nb;

	str[count] = '\0';
	if (n < 0)
		n = -n;
	while (count--)
	{
		nb = n % 10;
		str[count] = nb + '0';
		n /= 10;
	}
	return (str);
}

static size_t	ft_size_numbers(long num)
{
	unsigned int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	count;

	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	count = ft_size_numbers((long)n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	ft_numtochar((long)n, str, count);
	if (n < 0)
		str[0] = '-';
	return (str);
}
