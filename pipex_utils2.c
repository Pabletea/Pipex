/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:40:17 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/28 11:55:36 by pabalons         ###   ########.fr       */
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

void new_p_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env)
{
    int pid;

    pid = fork();
    if (pid < 0)
    {
        print_error("Error on fork");
        exit(1);
    }
    if (pid == 0)
    {
        close_fd((*p1)[1],(*p2)[0]);
        execute_command(cmd, (*p1)[0], (*p2)[1], env);
    }
    check_pipes(p1);
}

void new_s_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env)
{
    int pid;
    pid = fork();
    if (pid < 0)
        print_error("Error when forking (1).");
    if (pid == 0)
    {
        close_fd((*p1)[0],(*p2)[1]);
        execute_command(cmd,(*p2)[0],(*p1)[1],env);
    }
    check_pipes(p2);
}

void execute_command(char *buff, int intput_fd, int output_fd, char **env)
{
    char **args;
    char **paths;

    dup2(intput_fd, STDIN_FILENO);
    dup2(output_fd, STDOUT_FILENO);
    paths = get_path(env);
    args = ft_split(buff,' ');
    args[0] = get_exec(args[0],paths);
    execve(args[0], args, env);
}

void wait_children(int i)
{
    int status;
    
    while(i-- > 0)
        wait(&status);
}