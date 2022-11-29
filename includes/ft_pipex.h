/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:31:19 by arastell          #+#    #+#             */
/*   Updated: 2022/11/28 10:15:12 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../library/ft_printf/includes/ft_printf.h"
# include "../library/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_data
{
	char	**cmd;
	char	**env_path;
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
}	t_data;

void	ft_fill_data(int argc, char **argv, char **env, t_data *data);
void	ft_free_split(char **strs);
void	ft_fill_cmd_data(int index, char **argv, t_data *data);
void	ft_close_multiple_fd(t_data data);
t_data	ft_parse_data(char **argv);
int		ft_valid_cmd(t_data data);
int		ft_fd_is_valid(t_data data);
int		ft_get_cmd_path(t_data *data);
int		ft_fd_is_valid(t_data data);
void	ft_fork_1(t_data *data, char **argv, char **env);
void	ft_fork_2(t_data *data, char **argv, char **env);

#endif