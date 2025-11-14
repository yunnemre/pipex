/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 04:11:22 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/14 19:00:54 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	error_man(EXEC_ERR, data);
}

static void	open_next_pipe(int fd[2], t_pipex *data)
{
	if (pipe(fd) == -1)
		error_man(PIPE_ERR, data);
}

static pid_t	create_child(char *cmd, int in_fd, int out_fd, t_pipex *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_man(FORK_ERR, data);
	if (pid == 0)
		exec_cmd(cmd, in_fd, out_fd, data);
	return (pid);
}

static void	update_fds(int fd[2], int *in_fd, t_pipex *data)
{
	close(fd[1]);
	if (*in_fd != data->fd_in)
		close(*in_fd);
	*in_fd = fd[0];
}

void	pipex(char **argv, t_pipex *data)
{
	int		fd[2];
	int		in_fd;
	pid_t	pid;
	int		i;

	in_fd = data->fd_in;
	i = 1;
	while (++i < data->n - 2)
	{
		open_next_pipe(fd, data);
		create_child(argv[i], in_fd, fd[1], data);
		update_fds(fd, &in_fd, data);
	}
	pid = create_child(argv[i], in_fd, data->fd_out, data);
	while (wait(NULL) > 0)
		;
	(void)pid;
}
