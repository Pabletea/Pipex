/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:27:34 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/04 10:27:37 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = s;
	while (n)
	{
		*tmp_ptr = (unsigned char)c;
		tmp_ptr++;
		n--;
	}
	return (s);
}
