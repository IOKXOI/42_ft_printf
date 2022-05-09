/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:08:41 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/09 06:00:02 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_struct
{
	int		null_char;
	size_t	form_offset;
	size_t	buff_offset;
	size_t	wrote;
}	t_struct;

int		ft_printf(const char *format, ...);
char	*ft_strdup(char *src);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, char *base);
char	*ft_itoa_u(size_t n);
char	*ft_itoa_base_u(size_t n, char *base);
char	*converter(const char *format, t_struct *data, va_list args);

#endif
