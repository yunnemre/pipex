/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_man_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 01:48:49 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/13 11:53:40 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	else if (PIPE_ERR)
		perror("Pipe Error");
	else if (FORK_ERR)
		perror("Fork Error");
	else if (EXEC_ERR)
		perror("Execve Error");
	clear_all(data);
	exit(1);
}
