/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:08:52 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/22 15:27:47 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int				ft_printf(char *fmt, ...);


/*
** Conversions: c,s,p,d,i,o,u,x,X
*/
int				c_handle(char **fmt, va_list *vargs);
int				s_handle(char **fmt, va_list *vargs);
int				p_handle(char **fmt, va_list *vargs);
int				di_handle(char **fmt, va_list *vargs);
int				o_handle(char **fmt, va_list *vargs);
int				u_handle(char **fmt, va_list *vargs);
int				xX_handle(char **fmt, va_list *vargs);
