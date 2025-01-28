/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:30 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/28 16:45:39 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ar, char **av, char **env)
{
//Creamos los pipes para el proceso
    int fd[2];
    pid_t pid1;

    if (ar == 5)
    {
        if (pipe(fd) == -1)
            print_error();
        pid1 = fork();
        if (pid1 == -1)
            print_error();
        if (pid1 == 0)
            child_process(av, env, fd);
        waitpid(pid1, NULL , 0);
        parent_process(av,env,fd);
    }
    else
    {
        ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m",2);
        ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n",1);
    }
    return 0;
}