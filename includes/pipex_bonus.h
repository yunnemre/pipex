/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:45:34 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/14 16:20:51 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include <errno.h> // check

# define INV_ARGS "Invalid Arguments or more | less arguments"
# define OPEN_ERR 1
# define PATH_CRT_ERR 2
# define PATH_NOT_FOUND 3
# define PIPE_ERR 4
# define FORK_ERR 5
# define EXEC_ERR 6

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	char	**paths;
	int		n;
}		t_pipex;

//main.c
char	*ft_strjoin_with_slash(char **paths, char *cmd);

// arg_man.c
void	find_path(char **envp, t_pipex *data);
void	arg_man(char **args, char **envp, t_pipex *data);

// err_man.c
void	error_man(int code, t_pipex *data);
void	clear_all(t_pipex *data);

// pipex.c
void	pipex(char **argv, t_pipex *data);

void	here_doc(char **args, t_pipex *data);
// void	here_pipex(char **argv, t_pipex *data);
#endif
