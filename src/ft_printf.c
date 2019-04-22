/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:49 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/22 15:18:43 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		c_handle(char **fmt, va_list *vargs)
{
	char	c;

	c = (char)va_arg(*vargs, int);
	ft_putchar(c);
	return (1);
}

int		s_handle(char **fmt, va_list *vargs)
{
	char	*str;

	str = va_arg(*vargs, char*);
	ft_putstr(str);
	return (ft_strlen(str));
}

int				p_handle(char **fmt, va_list *vargs)
{
	uintmax_t	addr;
	char		*str;
	int			len;

	addr = va_arg(*vargs, uintmax_t);
	ft_putstr("0x");
	str = ft_itoa_base_unsigned(addr, 16);
	ft_putstr(str);
	len = 2 + ft_strlen(str);
	free(str);
	return (len);
}

int		di_handle(char **fmt, va_list *vargs)
{
	long long	nbr;

	nbr = va_arg(*vargs, long long);
	ft_putnbr(nbr);
	return (ft_numdigit(nbr));
}

int		o_handle(char **fmt, va_list *vargs)
{
	uintmax_t	nbr;
	char		*str;
	int			len;

	nbr = va_arg(*vargs, uintmax_t);
	str = ft_itoa_base_unsigned(nbr, 8);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		u_handle(char **fmt, va_list *vargs)
{
	uintmax_t	nbr;
	char		*str;
	int			len;

	nbr = va_arg(*vargs, uintmax_t);
	str = ft_itoa_base_unsigned(nbr, 10);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int				xX_handle(char **fmt, va_list *vargs)
{
	uintmax_t	nbr;
	char		*str;
	int			len;
	int			i;

	i = -1;
	nbr = va_arg(*vargs, uintmax_t);
	str = ft_itoa_base_unsigned(nbr, 16);
	if (**fmt == 'x')
		ft_putstr(str);
	else
	{
		while (str[++i])
			str[i] = ft_toupper(str[i]);
		ft_putstr(str);
	}
	len = ft_strlen(str);
	free(str);
	return (len);
}


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
	ft_printf("ft_printf: %X\n", x);
	printf("printf:  %X\n", x);
	return (0);
}


























