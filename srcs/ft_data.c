/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:16:48 by arastell          #+#    #+#             */
/*   Updated: 2022/11/28 10:14:05 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

static void	ft_cat_path(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i] != 0)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(path[i]) + 10));
		ft_strlcpy(tmp, path[i], ft_strlen(path[i]) + 1);
		ft_strlcat(tmp, "/", ft_strlen(tmp) + 2);
		free(path[i]);
		path[i] = tmp;
		i++;
	}
}

static char	**ft_get_path(char **env)
{
	char	**path;
	char	*trim;
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
			break ;
		i++;
	}
	trim = ft_strtrim(env[i], "PATH=");
	path = ft_split(trim, ':');
	if (trim)
		free(trim);
	ft_cat_path(path);
	return (path);
}

void	ft_fill_data(int argc, char **argv, char **env, t_data *data)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		ft_printf("Error with open infile\n");
		exit(EXIT_FAILURE);
	}
	data->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (data->outfile < 0)
	{
		ft_printf("Error with open outfile\n");
		exit(EXIT_FAILURE);
	}
	data->env_path = ft_get_path(env);
}

void	ft_fill_cmd_data(int index, char **argv, t_data *data)
{
	data->cmd = ft_split(argv[index], ' ');
}

int	ft_get_cmd_path(t_data *data)
{
	char	*join;
	int		i;

	i = 0;
	while (data->env_path[i] != 0)
	{
		join = ft_strjoin(data->env_path[i], data->cmd[0]);
		if (access(join, F_OK) == 0)
		{
			free(join);
			data->cmd[0] = ft_strjoin(data->env_path[i], data->cmd[0]);
			return (1);
		}
		free(join);
		i++;
	}
	return (0);
}
