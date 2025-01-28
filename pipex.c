/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:30 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/28 12:06:42 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ar, char **av, char **env)
{
//Creamos los pipes para el proceso
    int pipe[2], pipe2[2];
    int i, here_doc;

    ar_check(ar);
    check_pipes(&pipe);
    check_pipes(&pipe2);

    here_doc = check_here_doc(av, &pipe2);
    i = 0;
    while (i < ar - here_doc - 3)
    {
        if(i % 2 == 0)
            new_p_process(av[1 + here_doc + 2], &pipe2, &pipe, env);
        else
            new_s_process(av[1 + here_doc + 2], &pipe2, &pipe, env);
        i++;    
    }

    // Cierra descriptores no necesarios
    close_fd(pipe[1], pipe2[1]);

    // Espera a los procesos hijos
    wait_children(i);

    // Escribe el resultado final
    write_result(ar, av, &pipe, &pipe2);

    return 0;
}