/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:56:14 by pshcherb          #+#    #+#             */
/*   Updated: 2025/03/14 15:00:18 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process1(int *p_fd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_handling(1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	ft_exec(argv[3], envp);
}

void	child_process0(int *p_fd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		error_handling(1);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	ft_exec(argv[2], envp);
}

void	ft_exec(char *cmd, char **envp)
{
	char	*path;
	char	**my_cmd;

	my_cmd = ft_split(cmd, ' ');
	if (!my_cmd)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 2);
		exit (1);
	}
	path = get_path(my_cmd, envp);
	if (!path)
	{
		ft_putstr_fd("Error: command not found.\n", 2);
		ft_free_tab(my_cmd);
		exit (127);
	}
	if (execve(path, my_cmd, envp) == -1)
	{
		perror("execve");
		free(path);
		ft_free_tab(my_cmd);
		exit (1);
	}
}
