/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:51:07 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/16 02:14:30 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_com(char **args, t_pipex *data)
{
	char	*res;
	char	**com;
	int		i;
	int		j;

	i = 2;
	while (i < 4)
	{
		com = ft_split(args[i], ' ');
		res = ft_strjoin_with_slash(data->paths, com[0]);
		j = 0;
		while (com[j])
			free(com[j++]);
		free(com);
		if (!res || !*res)
			return (1);
		free(res);
		i++;
	}
	return (0);
}

int	main(int argc, char **args, char **envp)
{
	t_pipex	data;

	data.fd_in = -1;
	data.fd_out = -1;
	data.paths = NULL;
	if (argc < 5 || argc > 5)
		perror(INV_ARGS);
	else if (argc == 5)
	{
		arg_man(args, envp, &data);
		if (check_com(args, &data))
			error_man(COMMAND_NOT_FOUND, &data);
		pipex(args, &data);
		clear_all(&data);
	}
	return (0);
}
