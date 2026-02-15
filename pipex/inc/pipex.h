/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:43:06 by pshcherb          #+#    #+#             */
/*   Updated: 2025/03/13 13:54:33 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

void	ft_exec(char *cmd, char **envp);
void	do_pipe(char *cmd, char **envp);
void	here_doc(char **argv);
void	here_doc_put_in(int *p_fd, char **argv);
void	child_process0(int *p_fd, char **argv, char **envp);
void	child_process1(int *p_fd, char **argv, char **envp);
char	*get_path(char **my_cmd, char **envp);
void	ft_free_tab(char **tab);
void	handle_multiple_pipes(int argc, char **argv, char **envp);
void	error_handling(int i);
void	handle_here_doc(int argc, char **argv, char **envp);
void	simple_pipex(char **argv, char **envp);
char	*join_path(char **mypaths, char *my_cmd);

#endif
