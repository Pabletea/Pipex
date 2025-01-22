/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:51:27 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/22 22:14:51 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void pip_write_result(int ac, char *av[], int pipe1[2], int pipe2[2]) 
{
    int fd_output;
    char buffer[4096];
    ssize_t bytes_read;

    // Determinar el archivo de salida, si se proporciona
    if (ac > 1) {
        fd_output = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd_output < 0) {
            perror("Error al abrir archivo de salida");
            exit(EXIT_FAILURE);
        }
    } else {
        fd_output = STDOUT_FILENO; // Escribir en la salida estándar
    }

    // Cerrar extremos no utilizados de los pipes
    close(pipe1[1]);
    close(pipe2[1]);

    // Leer del pipe1 (extremo de lectura) y escribir en el destino
    while ((bytes_read = read(pipe1[0], buffer, sizeof(buffer))) > 0) {
        if (write(fd_output, buffer, bytes_read) != bytes_read) {
            perror("Error al escribir resultado");
            close(pipe1[0]);
            if (fd_output != STDOUT_FILENO) close(fd_output);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read < 0) {
        perror("Error al leer del pipe");
    }

    // Cerrar el archivo de salida si no es la salida estándar
    close(pipe1[0]);
    if (fd_output != STDOUT_FILENO) {
        close(fd_output);
    }
}

void free_split(char **split_arr)
{
    int i = 0;
    while (split_arr[i])
    {
        free(split_arr[1]);
        i++;
    }
    free(split_arr);
}
