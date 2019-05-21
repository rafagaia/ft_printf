/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:08:52 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/15 22:46:09 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

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
int				get_nbr(char *fmt, char c);

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
int				x_handle(t_token *fmt_token, va_list *vargs);
int				percent_handle(t_token *fmt_token);

/*
** modifiers.c:
** Handles both Signed and Unsigned [length] modifier
** (-1) Sign handles signed numbers. whereas (1) handles unsigned
*/

uintmax_t		length_handle(int sign, char *modifier, va_list *vargs);
char			*padding_handle(char flag, int width, char *str);
char			*precision_handle(t_token *fmt_token, char *str);

#endif
