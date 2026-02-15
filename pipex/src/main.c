/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:45:08 by pshcherb          #+#    #+#             */
/*   Updated: 2025/03/14 14:59:50 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	do_pipe(char *cmd, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		error_handling(2);
	pid = fork();
	if (pid == -1)
		error_handling(2);
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		ft_exec(cmd, envp);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

void	simple_pipex(char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		error_handling(2);
	pid = fork();
	if (pid == -1)
		error_handling(2);
	if (!pid)
		child_process0(p_fd, argv, envp);
	close(p_fd[1]);
	pid = fork();
	if (pid == -1)
		error_handling(2);
	if (!pid)
		child_process1(p_fd, argv, envp);
	close(p_fd[0]);
	wait(NULL);
	wait(NULL);
}

void	handle_multiple_pipes(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;

	i = 2;
	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		error_handling(1);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		error_handling(1);
	dup2(fd_in, 0);
	close(fd_in);
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	close(fd_out);
	ft_exec(argv[argc - 2], envp);
}

void	handle_here_doc(int argc, char **argv, char **envp)
{
	int	fd_out;
	int	i;

	if (argc < 6)
	{
		ft_putstr_fd("Error: here_doc: too few arguments\n", 2);
		ft_putstr_fd("Usage: here_doc LIMITER cmd1 cmd2 ...  file2\n", 2);
		exit(1);
	}
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd_out == -1)
		error_handling(1);
	here_doc(argv);
	if (argc == 6)
		do_pipe(argv[3], envp);
	else
	{
		i = 3;
		while (i < argc - 2)
			do_pipe(argv[i++], envp);
	}
	dup2(fd_out, 1);
	close(fd_out);
	ft_exec(argv[argc - 2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: wrong number of arguments.\n", 2);
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 ... file2\n", 2);
		exit(1);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		handle_here_doc(argc, argv, envp);
		return (0);
	}
	if (argc == 5)
		simple_pipex(argv, envp);
	else
		handle_multiple_pipes(argc, argv, envp);
	return (0);
}
