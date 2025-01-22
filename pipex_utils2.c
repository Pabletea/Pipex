/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:40:17 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/22 22:14:38 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void read_here_doc(char *lim,int fd_input, int output_fd)
{
    char *line;
    size_t lim_l;

    lim_l = ft_strlen(lim);

    while (1)
    {
        line = get_next_line(fd_input);
        if (!line)
        {
            print_error("Error reading from input");
            break;
        }
        if(ft_strncmp(line,lim, lim_l) == 0 && line[lim_l] == '\n')
        {
            free(line);
            break;
        }
        ft_putstr_fd(line, output_fd);
        free(line);
    }
}

void new_process(char *cmd, int pipe_input[2], int pipe_output[2], char **env, int is_first_process)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        print_error("Error on fork");
        exit(1);
    }
    if (pid == 0)
    {
        prepare_child(pipe_input,pipe_output,is_first_process);
        execute_command(cmd, env);
    }else
    {
        close(pipe_input[0]);
        close(pipe_output[0]);
    }
}

void prepare_child(int pipe_input[2], int pipe_output[2], int is_first_process)
{
    close(pipe_input[1]);
    close(pipe_output[0]);

    if (is_first_process == 0)
    {
        if (dup2(pipe_input[0],STDERR_FILENO) < 0)
        {
            print_error("Error on input redirect");
            exit(1);
        }
    }

    if (dup2(pipe_output[1],STDOUT_FILENO) < 0)
    {
        print_error("Error on output redirect");
        exit(1);
    }
    close(pipe_input[0]);
    close(pipe_output[1]);
}

void execute_command(char *cmd, char **env)
{
    char **args;

    // Divide el comando en argumentos usando ft_split
    args = ft_split(cmd, ' ');
    if (!args || !args[0]) {
        perror("Error al dividir el comando");
        if (args) free_split(args);
        exit(EXIT_FAILURE);
    }

    // Ejecuta el comando
    if (execve(args[0], args, env) < 0) {
        perror("Error al ejecutar comando");
        free_split(args);
        exit(EXIT_FAILURE);
    }

    // Libera memoria (no debería ejecutarse debido a execve)
    free_split(args);
}
void wait_children(int procress_count)
{
    int status;
    pid_t pid;
    int i = 0;

    while (i < procress_count)
    {
        pid = wait(&status);
        if(pid == -1)
        {
            print_error("Error waiting for child process");
            exit(1);
        }
        if (WIFEXITED(status))
            printf("Child process %d ended with state %d\n",pid,WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            printf("Child process %d ended due to signal %d\n",pid,WTERMSIG(status));
        else
            printf("Child process ended unexpectedly\n");
        i++;
    }
}