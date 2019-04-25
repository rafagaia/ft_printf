/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:08:52 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/25 05:59:28 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h> //DELETE BEFORE SUBMITTING

typedef struct	s_token
{
	char		flag;
	int			width;
	int			precision;
	char		length[3];
	char		conversion;
}				t_token;


int				ft_printf(char *fmt, ...);

/*
** tokenizer.c
*/
int				build_token(char *fmt, t_token *fmt_token);

/*
** cspdiu_conversions.c:
*/
int				c_handle(t_token *fmt_token, va_list *vargs);
int				s_handle(t_token *fmt_token, va_list *vargs);
int				p_handle(t_token *fmt_token, va_list *vargs);
int				di_handle(t_token *fmt_token, va_list *vargs);
int				u_handle(t_token *fmt_token, va_list *vargs);

/*
** oxXf_conversions.c:
*/
int				o_handle(t_token *fmt_token, va_list *vargs);
int				xX_handle(t_token *fmt_token, va_list *vargs);

