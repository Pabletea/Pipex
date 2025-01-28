/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:27:15 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/28 16:53:50 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void close_fd(int fd, int fd2)
{
    close(fd);
    close(fd2);
}

void print_error(void)
{
    perror("\033[31mError");
    exit(EXIT_FAILURE);
}


void check_pipes(int (*p)[2])
{
    close_fd((*p)[0],(*p)[1]);
    pipe((*p));
}


