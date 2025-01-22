/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:27:15 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/21 20:20:26 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void close_fd(int fd, int fd2)
{
    close(fd);
    close(fd2);
}

void print_error(char *s)
{
    ft_putstr_fd(s,STDERR_FILENO);
    exit(1);
}


void check_pipes(int (*p)[2])
{
    close_fd((*p)[0],(*p)[1]);
    pipe((*p));
}

void ar_check(int ar)
{
    if (ar < 5)
        print_error("Error en los argumentos\n");    
}

int check_here_doc(char **av, int (*p)[2])
{
    int tmp_fd;

    tmp_fd = open(av[1],O_RDWR);
    if (tmp_fd < 0)
    {
        print_error("Error openning file\n");
        return -1;
    }
    if (ft_strncmp(av[1],"here_doc",8) == 0)
    {
        close(tmp_fd);
        return 1;
    }
    (*p)[0] = tmp_fd;
    return 0;
}