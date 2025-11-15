/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:45:34 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/16 02:24:43 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include <errno.h> // check

# define INV_ARGS "More | less arguments\nExp: ./pipex infile cmd1 cmd2 outfile"
# define OPEN_ERR 1
# define PATH_CRT_ERR 2
# define PATH_NOT_FOUND 3
# define PIPE_ERR 4
# define FORK_ERR 5
# define EXEC_ERR 6
# define COMMAND_NOT_FOUND 7

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	char	**paths;
}		t_pipex;

//main.c
int		check_com(char **args, t_pipex *data);

// arg_man.c
void	arg_man(char **args, char **envp, t_pipex *data);
char	*ft_strjoin_with_slash(char **paths, char *cmd);
// err_man.c
void	error_man(int code, t_pipex *data);
void	clear_all(t_pipex *data);

// pipex.c
void	pipex(char **argv, t_pipex *data);
#endif
