/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:51:07 by ydinler           #+#    #+#             */
/*   Updated: 2025/07/17 14:46:06 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/pipex.h"

int main(int argv, char **args, char **envp)
{
	if (argv < 5)
		perror(TOO_FEW_ARGS);
	else if (argv > 5)
		perror(TOO_MANY_ARGS);
	else if (argv == 5)
	{
		int i = 0;
		while (envp[i])
			printf("%s\n",envp[i++]);
	}

	return (0);
}
