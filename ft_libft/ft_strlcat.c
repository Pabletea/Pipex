/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:50 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/04 10:31:54 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;
	size_t	len_src;

	if ((!dst && !src) && size > 0)
		return (0);
	i = 0;
	len_dst = 0;
	len_src = 0;
	while (src[len_src])
		len_src++;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	if (len_dst >= size)
		return (size + len_src);
	while (src[i] && len_dst + i + 1 < size)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
