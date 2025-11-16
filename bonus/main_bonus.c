/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:51:07 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/16 02:56:45 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_com(char **args, t_pipex *data, int tour, int mode)
{
	char	*res;
	char	**com;
	int		i;
	int		j;

	if (mode == 1)
		i = 1;
	else
		i = 2;
	while (++i < tour)
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
	}
	return (0);
}

int	main(int argc, char **args, char **envp)
{
	t_pipex	data;

	data.fd_in = -1;
	data.fd_out = -1;
	data.paths = NULL;
	data.n = argc;
	if (argc < 5)
		perror(INV_ARGS);
	else if (argc == 6 && !(ft_strncmp(args[1], "here_doc", 9)))
	{
		find_path(envp, &data);
		here_doc(args, &data);
		clear_all(&data);
	}
	else if (argc >= 5)
	{
		arg_man(args, envp, &data);
		if (check_com(args, &data, data.n - 1, 1))
			error_man(COMMAND_NOT_FOUND, &data);
		pipex(args, &data);
		clear_all(&data);
	}
	return (0);
}
//argman ya file acmayı duzelticeksin yada yeni 
//bir sisten altına yazıcaksın heredoc icin
//here_pipex(args, &data); 
// burdan dinlemeyi yazıp limiter durup
// onu arguman olrak yazıcan sonra write 
//herhalde fd icine yazıcaksı nsonra fork 
//ile comutlşarı uygularsın gibi geliyor . denendcek