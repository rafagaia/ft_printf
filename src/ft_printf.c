/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:49 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/25 05:53:11 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		token_handler(t_token *fmt_token, va_list *vargs)
{
	int		len;
	char	c;

	len = 1;
	c = fmt_token->conversion;
	if (c == '%')
		ft_putstr("%");
	else if (c == 'c')
		len = c_handle(fmt_token, vargs);
	else if (c == 's')
		len = s_handle(fmt_token, vargs);
	else if (c == 'p')
		len = p_handle(fmt_token, vargs);
	else if ((c == 'd') || (c == 'i'))
		len = di_handle(fmt_token, vargs);
	else if (c == 'o')
		len = o_handle(fmt_token, vargs);
	else if (c == 'u')
		u_handle(fmt_token, vargs);
	else if ((c == 'x') || (c == 'X'))
		xX_handle(fmt_token, vargs);
	else
		ft_putchar(c);
	return (len);
}

/*
** Printf must handle all the following:
** 1. Conversions:
**		c, s, p, d, i, o, u, x, X, f
** 2. With FLAGS:
**		h, hh, l, ll
**		#, 0, -, +, space
** 3. Must manage: 
**		%% (percent character)
**		Minimum field-width
**		Precision
*/
int				ft_printf(char *fmt, ...)
{
	int			len; //ft_printf total output string length
	t_token		fmt_token;
	va_list		vargs;

	len = 0;
	va_start(vargs, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++; //increment to index after '%'
			if (build_token(fmt, &fmt_token))
			{
				len += token_handler(&fmt_token, &vargs);
				fmt = ft_strchr(fmt, fmt_token.conversion);
			}
			else
				write(1, fmt, 1);
		}
		else
		{
			len += write(1, fmt, 1);
		}
		++fmt;
	}
	va_end(vargs);
	return (len);
}






