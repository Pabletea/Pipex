/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:09:20 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/04 10:09:24 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_signo(const char *str, int *i);

int	ft_atoi(const char *str)
{
	int	resultado;
	int	signo;
	int	i;

	resultado = 0;
	signo = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signo = check_signo(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (resultado > (2147483647 - (str[i] - '0')) / 10)
		{
			if (signo == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		resultado = resultado * 10 + (str[i] - '0');
		i++;
	}
	return (resultado * signo);
}

static int	check_signo(const char *str, int *i)
{
	int	signo;

	signo = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			signo = -1;
		(*i)++;
	}
	return (signo);
}
