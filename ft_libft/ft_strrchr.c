/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:34:46 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/04 10:34:49 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tar;
	char	*res;
	char	*tmp;

	tar = (char)c;
	tmp = (char *)s;
	res = NULL;
	while (*tmp)
	{
		if (*tmp == tar)
			res = tmp;
		tmp++;
	}
	if (!tar)
		return (tmp);
	else
		return (res);
}
