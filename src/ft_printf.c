/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:49 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/22 15:38:48 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h> //DELETE - USE FOR TESTING ONLY

int		format_handler(char **fmt, va_list *vargs)
{
	int		len;

	len = 1;
	if (**fmt == '%')
		ft_putstr("%");
	else if (**fmt == 'c')
		len = c_handle(fmt, vargs);
	else if (**fmt == 's')
		len = s_handle(fmt, vargs);
	else if (**fmt == 'p')
		len = p_handle(fmt, vargs);
	else if ((**fmt == 'd') || (**fmt == 'i'))
		len = di_handle(fmt, vargs);
	else if (**fmt == 'o')
		len = o_handle(fmt, vargs);
	else if (**fmt == 'u')
		u_handle(fmt, vargs);
	else if ((**fmt == 'x') || (**fmt == 'X'))
		xX_handle(fmt, vargs);
	else
		ft_putchar(**fmt);
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
int		ft_printf(char *fmt, ...)
{
	int			len;
	va_list		vargs;

	len = 0;
	va_start(vargs, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++; //increment to index after '%'
			len += format_handler(&fmt, &vargs);
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

int		main(void)
{
	int		x;
	char	str[1];

	str[0] = '@';
	x = 255;
	// Known issue: ft_printf("%d\tLife"); will output space instead of tab.Why?
	ft_printf("ft_printf: c:%c; s:%s; p:%p\n", 'c', "ass", &x);
	printf("printf: c:%c; s:%s; p:%p\n", 'c', "ass", &x);
	
	return (0);
}


























