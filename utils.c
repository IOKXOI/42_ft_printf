/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 04:05:40 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/10 09:27:15 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "ft_printf.h"

static size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
char *nill_case(void)
{
	char *nxll;
	
	nxll = malloc(sizeof(char) * 7);
	nxll[0] = '(';
	nxll[1] = 'n';
	nxll[2] = 'i';
	nxll[3] = 'l';
	nxll[4] = ')';
	nxll[5] = '\0';
	return (nxll);
}*/

char *ft_strdup(char *src)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (ft_strdup("(null)"));
	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

