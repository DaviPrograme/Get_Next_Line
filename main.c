/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:06:26 by davi              #+#    #+#             */
/*   Updated: 2020/05/11 20:03:43 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char **ptr;
	int ret;
	char path[] = "";
	fd = open(path, O_RDONLY);
	while ((ret = get_next_line(fd, ptr)) > 0)
		printf("Return: %d     string:%s:\n", ret, *ptr);
	printf("Return: %d     string:%s:\n", ret, *ptr);
	return (0);
}
