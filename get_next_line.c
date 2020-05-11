/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		initialize_gnl(t_gnl *gnl, int fd)
{
	int		cont;

	cont = 0;
	if (gnl->status == NULL)
	{
		gnl->ret = read(fd, gnl->string, BUFFER_SIZE);
		if (gnl->ret > 0)
			gnl->value = 1;
		else if (gnl->ret < 0)
			gnl->value = -1;
		else
			gnl->value = 0;
		gnl->status = gnl->string;
	}
	gnl->nread = 0;
	gnl->aux_int = 0;
}

int			get_next_line(int fd, char **line)
{
	static	t_gnl gnl;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (gnl.status == NULL)
		initialize_gnl(&gnl, fd);
	if (gnl.ret < 0)
		return (-1);
	*line = line_pointer(&gnl, fd);
	if (gnl.string[gnl.nread] == '\n')
		gnl.nread += 1;
	if (gnl.ret < BUFFER_SIZE && gnl.nread > gnl.ret)
		gnl.value = 0;
	return (gnl.value);
}

char		*line_pointer(t_gnl *gnl, int fd)
{
	char	*ptr;
	char	*ptr2;

	gnl->aux_int = gnl->nread;
	while (gnl->string[gnl->aux_int] != '\n' && (gnl->aux_int < gnl->ret))
		gnl->aux_int += 1;
	ptr = ft_substr(gnl->string, gnl->nread, (gnl->aux_int - gnl->nread));
	while (gnl->string[gnl->aux_int] != '\n' && gnl->value > 0)
	{
		gnl->status = NULL;
		initialize_gnl(gnl, fd);
		while (gnl->string[gnl->aux_int] != '\n' && gnl->aux_int < gnl->ret)
			gnl->aux_int += 1;
		ptr2 = ft_substr(gnl->string, gnl->nread, gnl->aux_int);
		gnl->aux_char = ptr;
		ptr = ft_strjoin(gnl->aux_char, ptr2);
		free(gnl->aux_char);
		free(ptr2);
	}
	gnl->nread = gnl->aux_int;
	return (ptr);
}
