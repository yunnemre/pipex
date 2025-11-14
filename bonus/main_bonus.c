/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:51:07 by ydinler           #+#    #+#             */
/*   Updated: 2025/11/15 01:46:34 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		pipex(args, &data);
		clear_all(&data);
	}
	return (0);
}
//argman ya file acmayı duzelticeksin yada yeni bir sisten altına yazıcaksın heredoc icin
//here_pipex(args, &data); // burdan dinlemeyi yazıp limiter durup
// onu arguman olrak yazıcan sonra write 
//herhalde fd icine yazıcaksı nsonra fork ile comutlşarı uygularsın gibi geliyor . denendcek