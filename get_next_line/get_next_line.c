/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:29:19 by ncolomer          #+#    #+#             */
/*   Updated: 2021/07/25 19:12:19 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int get_next_line()
// {
// 	char *bf;

// 	read(3, bf, 1);
// 	while (*bf && *bf != '\n')
// 	{
// 		printf("%s", bf);
// 		read(3, bf, 1);
// 	}
	
// 	return 1;
// }

int main()
{
	int fd = open("subject.fr.txt", O_RDONLY);
	char bf[1];
	int n =0;

	do
	{
		if (read(fd, bf, 1) > 0)
			n++;
		write(1, bf, 1);

	}while (*bf && *bf != '\n');
	close(fd);
	printf("%d", n);
	return 0;
}