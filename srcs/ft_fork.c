/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:02:57 by alex              #+#    #+#             */
/*   Updated: 2022/11/28 10:14:16 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

static void	ft_execve(t_data *data, char **argv, char **env, int index)
{
	ft_fill_cmd_data(index, argv, data);
	if (!ft_get_cmd_path(data))
	{
		perror("Access");
		ft_free_split(data->cmd);
		ft_free_split(data->env_path);
		exit(EXIT_FAILURE);
	}
	if (execve(data->cmd[0], data->cmd, env) == -1)
	{
		perror("Execve");
		ft_free_split(data->cmd);
		ft_free_split(data->env_path);
		exit(EXIT_FAILURE);
	}
}

void	ft_fork_1(t_data *data, char **argv, char **env)
{
	close(data->fd[0]);
	dup2(data->fd[1], 1);
	dup2(data->infile, 0);
	ft_execve(data, argv, env, 2);
}

void	ft_fork_2(t_data *data, char **argv, char **env)
{
	close(data->fd[1]);
	dup2(data->fd[0], 0);
	dup2(data->outfile, 1);
	ft_execve(data, argv, env, 3);
}
