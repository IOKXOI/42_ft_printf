/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:08:41 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/10 09:13:34 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

typedef struct s_struct
{
	size_t	form_offset;
	size_t	buff_offset;
	size_t	wrote;
}	t_struct;

int		ft_printf(const char *format, ...);
char	*ft_strdup(char *src);
char	*nill_case(void);
char	*converter(const char *format, t_struct *data, va_list args);

#endif
