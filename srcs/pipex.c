/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 04:11:22 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/15 01:52:42 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

static void	exec_cmd(char *cmd, int in_fd, int out_fd, t_pipex *data)
{
	char	**com;
	char	*path;
	int		i;

	com = ft_split(cmd, ' ');
	path = ft_strjoin_with_slash(data->paths, com[0]);
	dup2(in_fd, 0);
	dup2(out_fd, 1);
	execve(path, com, NULL);
	i = 0;
	while (com[i])
		free(com[i++]);
	free(com);
	free(path);
	error_man(EXEC_ERR, data);
}

void	pipex(char **argv, t_pipex *data)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error_man(PIPE_ERR, data);
	pid = fork();
	if (pid < 0)
		error_man(FORK_ERR, data);
	if (pid == 0)
	{
		close(fd[0]);
		exec_cmd(argv[2], data->fd_in, fd[1], data);
	}
	pid = fork();
	if (pid < 0)
		error_man(FORK_ERR, data);
	if (pid == 0)
	{
		close(fd[1]);
		exec_cmd(argv[3], fd[0], data->fd_out, data);
	}
	close_fd(fd);
	waitpid(pid, NULL, 0);
}
