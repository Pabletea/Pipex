/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:32:54 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/04 10:42:45 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size)
	{
		while (*(src + len) && --size)
		{
			*dst++ = *(src + len);
			len++;
		}
		*dst = '\0';
	}
	while (src[len])
		len++;
	return (len);
}
