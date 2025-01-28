/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:40:17 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/28 16:48:57 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void read_here_doc(char *lim,int fd_input, int output_fd)
// {
//     char *line;
//     size_t lim_l;

//     lim_l = ft_strlen(lim);

//     while (1)
//     {
//         line = get_next_line(fd_input);
//         if (!line)
//         {
//             print_error("Error reading from input");
//             break;
//         }
//         if(ft_strncmp(line,lim, lim_l) == 0 && line[lim_l] == '\n')
//         {
//             free(line);
//             break;
//         }
//         ft_putstr_fd(line, output_fd);
//         free(line);
//     }
// }

void parent_process(char **av, char **env, int *fd)
{
    int file_out;

    file_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (file_out == -1)
        print_error();
    dup2(fd[0], STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    execute_command(av[3],env);
}

void child_process(char **av, char **env, int *fd)
{
    int file_in;

    file_in = open(av[1], O_RDONLY, 0777);
    if (file_in == -1)
        print_error();
    dup2(fd[1],STDOUT_FILENO);
    dup2(file_in,STDIN_FILENO);
    close(fd[0]);
    execute_command(av[2],env);
}

void execute_command(char *av, char **env)
{
    char **cmd;
    int i;
    char *path;

    i = -1;
    cmd = ft_split(av, ' ');
    path = find_path(cmd[0],env);
    if(!path)
    {
        while(cmd[++i])
            free(cmd[i]);
        free(cmd);
        print_error();
    }
    if (execve(path,cmd,env) == -1)
        print_error();
}

// void wait_children(int i)
// {
//     int status;
    
//     while(i-- > 0)
//         wait(&status);
// }

char *find_path(char *cmd, char **env)
{
    char **paths;
    char *path;
    int i;
    char *part_path;
    
    i = 0;
    while(ft_strnstr(env[i], "PATH", 4) == 0)
        i++;
    paths = ft_split(env[i] + 5, ':');
    i = 0;
    while(paths[i])
    {
        part_path = ft_strjoin(paths[i],"/");
        path = ft_strjoin(part_path,cmd);
        free(part_path);
        if (access(path, F_OK) == 0)
            return (path);
        free(path);
        i++;
    }
    i = -1;
    while(paths[++i])
        free(paths[i]);
    free(paths);
    return (0);
}