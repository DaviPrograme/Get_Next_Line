/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:10:55 by davi              #+#    #+#             */
/*   Updated: 2020/05/08 00:48:08 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;

	if (!s || !(ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	j = 0;
	while (j < len && ft_strlen(s) > start && (j += 1))
		ptr[j - 1] = s[j - 1 + start];
	ptr[j] = '\0';
	return (ptr);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cont_s1;
	size_t	cont_s2;
	size_t	cont;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	cont_s1 = ft_strlen(s1);
	cont_s2 = ft_strlen(s2);
	ptr = 0;
	if (!(ptr = malloc(cont_s1 + cont_s2 + 1)))
		return (NULL);
	cont = 0;
	ptr[cont_s1 + cont_s2] = '\0';
	while (cont < (cont_s1 + cont_s2))
	{
		if (cont < cont_s1)
			ptr[cont] = s1[cont];
		else
			ptr[cont] = s2[cont - cont_s1];
		++cont;
	}
	return (ptr);
}

size_t		ft_strlen(const char *vetor)
{
	int		cont;

	cont = 0;
	while (vetor[cont] != '\0')
		++cont;
	return (cont);
}
