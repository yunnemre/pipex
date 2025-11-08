/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:50:11 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/08 14:06:33 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_strjoin_with_slash(char **paths, char *cmd)
{
	char	*tmp;
	char	*result;
	int		i;
	
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		result = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(result, X_OK) == 0)
			return (result);
		free(result);
	}
	return (NULL);
}

static int	ft_find_path(char **envp)
{
	int	i;
	
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (i);
	}
	return (-1);
}

static void	open_files(char **args,t_pipex *data)
{
	data->fd_in = open(args[1], O_RDONLY);
	if (data->fd_in < 0)
		error_man(OPEN_ERR, data);
	data->fd_out = open(args[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (data->fd_out < 0)
		error_man(OPEN_ERR, data);
}

static void	find_path(char **envp, t_pipex *data)
{
	int	pth_index;
	
	pth_index = ft_find_path(envp);
	if (pth_index == -1)
		error_man(PATH_NOT_FOUND, data);
	data->paths = ft_split(envp[pth_index] + 5, ':');
	if (!data->paths | !*(data->paths))
		error_man(PATH_CRT_ERR, data);
}

void	arg_man(char **args, char **envp, t_pipex *data)
{
	open_files(args, data);
	find_path(envp, data);
}