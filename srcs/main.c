/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:30:53 by arastell          #+#    #+#             */
/*   Updated: 2022/11/28 10:14:34 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
	{
		ft_printf("Error in argument\n");
		return (EXIT_FAILURE);
	}
	ft_fill_data(argc, argv, env, &data);
	if (pipe(data.fd) == -1)
	{
		perror("Pipe");
		return (EXIT_FAILURE);
	}
	data.pid1 = fork();
	if (data.pid1 == 0)
		ft_fork_1(&data, argv, env);
	data.pid2 = fork();
	if (data.pid2 == 0)
		ft_fork_2(&data, argv, env);
	ft_close_multiple_fd(data);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	ft_free_split(data.env_path);
	return (0);
}
