/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:45:34 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/29 04:12:56 by ydinler          ###   ########.fr       */
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

# define INV_ARGS "Invalid Arguments or more | less arguments"
# define OPEN_ERR 1
# define PATH_CRT_ERR 2
# define PATH_NOT_FOUND 3


typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	char	**paths;
}		t_pipex;

//main.c
char	*ft_strjoin_with_slash(char **paths, char *cmd);

// arg_man.c
void	arg_man(char **args, char **envp, t_pipex *data);

// err_man.c
void	error_man(int code, t_pipex *data);
void	clear_all(t_pipex *data);

// pipex.c
void	pipex(int argc, char **argv, t_pipex *data);
#endif
