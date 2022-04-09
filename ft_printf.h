/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:08:41 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/09 07:05:01 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>

typedef struct s_struct
{
	size_t form_offset;
	size_t buff_offset;
	size_t wrote;
} t_struct;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(char *str);
char	*ft_getchar(char c);
char	*ft_strcpy(char *src);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, char *base);
char 	*ft_get_address(void *address);



# endif
