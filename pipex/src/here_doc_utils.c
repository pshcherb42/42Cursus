/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:56:05 by pshcherb          #+#    #+#             */
/*   Updated: 2025/03/13 15:56:07 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	here_doc_put_in(int *p_fd, char **argv)
{
	char	*line;

	close(p_fd[0]);
	while (1)
	{
		write(1, "here_doc> ", 9);
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& line[ft_strlen(argv[2])] == '\n')
		{
			free(line);
			exit (0);
		}
		ft_putstr_fd(line, p_fd[1]);
		free(line);
	}
}

void	here_doc(char **argv)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		error_handling(2);
	pid = fork();
	if (pid == -1)
		error_handling(2);
	if (pid == 0)
		here_doc_put_in(p_fd, argv);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}
