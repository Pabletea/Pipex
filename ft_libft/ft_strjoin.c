/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:36 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/04 10:31:38 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!new_str)
		return (NULL);
	while (s1 != NULL && s1[++j] != '\0')
		new_str[++i] = s1[j];
	j = -1;
	while (s2 != NULL && s2[++j] != '\0')
		new_str[++i] = s2[j];
	new_str[++i] = '\0';
	return (new_str);
}
