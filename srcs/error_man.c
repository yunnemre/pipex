/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 01:48:49 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/16 01:36:51 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_all(t_pipex *data)
{
	int	i;

	i = -1;
	if (data->fd_in > 0)
		close(data->fd_in);
	if (data->fd_out > 0)
		close(data->fd_out);
	if (!data->paths || !*(data->paths))
		return ;
	while (data->paths[++i])
		free(data->paths[i]);
	free(data->paths);
	data->paths = NULL;
}

void	error_man(int code, t_pipex *data)
{
	if (code == OPEN_ERR)
		perror ("Open error");
	else if (code == PATH_CRT_ERR)
		perror ("Malloc error");
	else if (code == PATH_NOT_FOUND)
		perror ("Path not found error");
	else if (code == PIPE_ERR)
		perror("Pipe Error");
	else if (code == FORK_ERR)
		perror("Fork Error");
	else if (code == EXEC_ERR)
		perror("Execve Error");
	else if (code == COMMAND_NOT_FOUND)
		perror("Command Not Found");
	clear_all(data);
	exit(1);
}
