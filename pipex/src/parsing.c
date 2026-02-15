/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:21:01 by pshcherb          #+#    #+#             */
/*   Updated: 2025/03/13 16:58:48 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_handling(int i)
{
	if (i == 1)
	{
		perror("open");
		exit(1);
	}
	if (i == 2)
	{
		perror("pipe/fork");
		exit(1);
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	*join_path(char **mypaths, char *my_cmd)
{
	int		i;
	char	*pre_path;
	char	*full_path;

	i = -1;
	while (mypaths[++i])
	{
		pre_path = ft_strjoin(mypaths[i], "/");
		full_path = ft_strjoin(pre_path, my_cmd);
		free(pre_path);
		if (!full_path)
			continue ;
		if (access(full_path, F_OK) == 0)
		{
			ft_free_tab(mypaths);
			return (full_path);
		}
		free(full_path);
	}
	ft_free_tab(mypaths);
	return (NULL);
}

char	*get_path(char **my_cmd, char **envp)
{
	int		i;
	char	*paths_from_envp;
	char	**mypaths;

	i = -1;
	if (my_cmd[0][0] == '/' || my_cmd[0][0] == '.')
	{
		if (access(my_cmd[0], F_OK) == 0)
			return (ft_strdup(my_cmd[0]));
		return (NULL);
	}
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			paths_from_envp = envp[i] + 5;
	if (!paths_from_envp)
		return (NULL);
	mypaths = ft_split(paths_from_envp, ':');
	if (!mypaths)
		return (NULL);
	return (join_path(mypaths, my_cmd[0]));
}
