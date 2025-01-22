/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:30 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/22 18:24:23 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ar, char **av, char **env)
{
//Creamos los pipes para el proceso
    int pipe[2], pipe2[2];
    int i, here_doc,  process_count;

    ar_check(ar);
    check_pipes(&pipe);
    check_pipes(&pipe2);

    here_doc = check_here_doc(av, &pipe2);
    i = 0;
    process_count = ar - here_doc - 3;
    while (i < process_count) {
        int is_first_process = (i % 2 == 0);
        char *cmd = av[i + here_doc + 2];
        new_process(cmd, is_first_process ? pipe2 : pipe, is_first_process ? pipe : pipe2, env, is_first_process);
        i++;
    }

    // Cierra descriptores no necesarios
    close_fd(pipe[1], pipe2[1]);

    // Espera a los procesos hijos
    pip_wait_children(process_count);

    // Escribe el resultado final
    pip_write_result(ar, av, pipe, pipe2);

    return 0;
}