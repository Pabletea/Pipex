/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:59:33 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/28 11:57:50 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define BUFFER_SIZE 100
# include "ft_libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stddef.h>

int open_file(char *file, int n);
void close_pipe(int pipeAr[2]);
void check_pipes(int (*p)[2]);
void wait_children(int num_children);
void print_error(char *s);
void ar_check(int ar);
int check_here_doc(char **av, int (*p)[2]);
void read_here_doc(char *lim,int fd_input, int ft_output);
void close_fd(int fd, int fd2);
char	*get_next_line(int fd);
void new_process(char *cmd, int pipe_input[2], int pipe_output[2], char **env, int is_first_process);
void new_s_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env);
void execute_command(char *buff, int intput_fd, int output_fd, char **env);
void wait_children(int procress_count);
void pip_write_result(int ac, char *av[], int pipe1[2], int pipe2[2]);
void free_split(char **split_arr);
char **get_path(char **env);
void no_exec(char *s);
char *get_exec(char *cmd, char **paths);
void new_p_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env);
void p_write(char *name, int input_fd, int hd);
void write_result(int ac, char **av, int (*op)[2], int (*ip)[2]);
#endif