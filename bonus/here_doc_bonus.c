/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:28:35 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/15 01:51:35 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static void	here_pipex(char **args, t_pipex *data)
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
		exec_cmd(args[3], data->fd_in, fd[1], data);
	}
	close(fd[1]);
	close(data->fd_in);
	pid = fork();
	if (pid < 0)
		error_man(FORK_ERR, data);
	if (pid == 0)
	{
		close(fd[1]);
		exec_cmd(args[4], fd[0], data->fd_out, data);
	}
	close_fd(fd);
	waitpid(pid, NULL, 0);
}

void	here_doc(char **args, t_pipex *data)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		error_man(PIPE_ERR, data);
	while (1)
	{
		write(0, "> ", 2);
		line = get_next_line(0);
		if (!ft_strncmp(line, args[2], ft_strlen(line) - 1))
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	data->fd_in = fd[0];
	data->fd_out = open(args[5], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (data->fd_out < 0)
		error_man(OPEN_ERR, data);
	here_pipex(args, data);
}

//cat << END | grep a >> result.txt