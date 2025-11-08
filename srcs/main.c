/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:51:07 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/29 15:47:25 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// TO DO first arguman ların dosyalrını acıcaksın acmada bir problem yapsarcan cıkıs 
	//yoksa sonra komut kontrollerine gircez path bul path hazır hale getir 
	//sonra komutlar var mı mesela komut yoksa hata mesajhı ver cık var sa fork tanımla işlemlere basla gibi gibi start vercezz 
	// sonra fork pipe gidicez ancak start arguman kontrolleri yetki kontrolleri dosya acılam kontorlleri hata kontrolleri yapılarak adım adım gidilecek


int main(int argc, char **args, char **envp)
{
	t_pipex	data;
	
	data.fd_in = -1;
	data.fd_out = -1;
	data.paths = NULL;
	if (argc < 5)
		perror(INV_ARGS);
	else if (argc == 5)
	{	
		arg_man(args, envp, &data);
		// write(data.fd_out,"yunn",4);
		// pipex(argc, args, &data); && TODO : AGA pipex diye birsey olustur onun icinde forkları yaratıp komutları parcalayıp islemleri yapıcan
		clear_all(&data); // TODO mallocla acılmıs fd ler icin acılmıs yerleri temizle
	}
	
	return (0);
}
