/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:20:49 by klee              #+#    #+#             */
/*   Updated: 2018/04/26 15:20:51 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int		main(void)
{
	int			fd;
	short int		data[] = {0x63, 0x20, 3, 4};

	fd = open("file.cor", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_printf("%d - fd\n", fd);
	if (fd == -1)
		ft_printf("ERROR CREATE\n");
	lseek(fd, 0, SEEK_END);
	write(fd, data, 32);
	// write(fd, mass1, sizeof(mass1));
	close(fd);
	return (0);
}
