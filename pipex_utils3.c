/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:51:27 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/28 11:46:58 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void write_result(int ac, char **av, int (*op)[2], int (*ip)[2]) 
{
    int here_d;
    
    here_d = 0;
    if (ft_strncmp(av[1], "here_doc",8) == 0)
        here_d = 1;
    if (((ac - here_d) % 2) == 0)
        p_write(av[ac - 1],(*op)[0], here_d);
    else
        p_write(av[ac - 1],(*ip)[0], here_d);
}

void p_write(char *name, int input_fd, int hd)
{
    int output_fd;
    int b_read;
    char buff[1];
    
    if(hd)
        output_fd = open(name, O_RDWR | O_CREAT | O_APPEND, 00777);
    else
    {
        if(access(name, F_OK) == 0)
            unlink(name);
        output_fd = open(name, O_WRONLY | O_CREAT, 00777);
    }
    if (output_fd < 0)
        print_error("p_write: output_fd error.");
    if (input_fd < 0)
        print_error("p_write: input_fd error.");
    b_read = read(input_fd, &buff, sizeof(char));
    while(b_read > 0)
    {
        write(output_fd,&buff,1);
        b_read = read(input_fd, &buff, sizeof(char));
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

char **get_path(char **env)
{
    char **paths;
    
    while(*env)
    {
        if (ft_strncmp(*env, "PATH", 4) == 0)
            break;
        env++;
    }
    paths = ft_split(*env + 5, ';');
    return(paths);
}

char *get_exec(char *cmd, char **paths)
{
    char *path;
    
	if ((ft_strncmp(cmd, "./", 2) == 0) && access(cmd, X_OK) == 0)
        return(ft_strdup(cmd));
    while(*paths)
    {
        path = ft_strjoin(*paths, "/");
        path = ft_strjoin(path,cmd);
        if (access(path, X_OK) == 0)
            return(path);
        paths++;
    }
    no_exec(cmd);
    return(NULL);
}

void no_exec(char *s)
{
    ft_putstr_fd("pipex: ",STDERR_FILENO);
    ft_putstr_fd(s,STDERR_FILENO);
    ft_putstr_fd(" : command not found.",STDERR_FILENO);
    exit(1);
}

