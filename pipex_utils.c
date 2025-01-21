/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:27:15 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/21 13:28:42 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void print_error(char *s)
{
    ft_putstr_fd(s,STDERR_FILENO);
    exit(1);
}


void renew_pipe(int (*p)[2])
{
    
    pipe((*p));
}

void ar_check(int ar)
{
    if (ar < 5)
        print_error("Error en los argumentos\n");    
}