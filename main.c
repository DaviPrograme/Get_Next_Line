/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:06:26 by davi              #+#    #+#             */
/*   Updated: 2020/05/11 20:26:30 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char *ptr;
	int ret;

	//na varável path insira o caminho do arquivo que deseja ler.
	char path[] = "texto.txt";
	fd = open(path, O_RDONLY);
	while ((ret = get_next_line(fd, &ptr)) > 0)
		printf("Return: %d     string:%s:\n", ret, ptr);
	printf("Return: %d     string:%s:\n", ret, ptr);
	return (0);
}
