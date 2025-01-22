/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:40:17 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/22 18:59:13 by pabalons         ###   ########.fr       */
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
    char *args[128];
    char *token = ft_split(cmd,32);
    int i = 0;

    while(token != NULL && i < 127)
    {
        args[i] = token;
        token = ft_split(NULL," ");
        i++;
    }
    args[i] = NULL;

    if (execve(args[0], args,env) < 0)
    {
        print_error("Error on executing command");
        exit(1);
    }
}