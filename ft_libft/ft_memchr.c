/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:25:06 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/04 10:38:01 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	target;

	str = (unsigned char *)s;
	target = (unsigned char)c;
	while (n--)
	{
		if (*str == target)
			return (str);
		str++;
	}
	return (NULL);
}
