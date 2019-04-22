/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:49 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/22 02:13:00 by rgaia            ###   ########.fr       */
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


//TODO
int		p_handle(char **fmt, va_list *vargs)
{
	void	*addr;

	addr = (void*)va_arg(*vargs, void*);
	ft_putstr("0x");
	ft_putnbr((int)addr);
	return (1);
}

int		di_handle(char **fmt, va_list *vargs)
{
	int		nbr;

	nbr = (int)va_arg(*vargs, int);
	ft_putnbr(nbr);
	ft_putchar('\n');
	ft_putnbr(ft_numdigit(nbr));
	return (ft_numdigit(nbr));
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
		len = p_handle(fmt, vargs);//TODO
	else if ((**fmt == 'd') || (**fmt == 'i'))
		len = di_handle(fmt, vargs);
	else if (**fmt == 'o')
		ft_putstr("[unsigned octal 'o']");
	else if (**fmt == 'u')
		ft_putstr("[unsigned int 'u']");
	else if (**fmt == 'x')
		ft_putstr("[unsigned hex lowercase 'x']");
	else if (**fmt == 'X')
		ft_putstr("[unsigned HEX uppercase 'X']");
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
	x = -223;
	// Known issue: ft_printf("%d\tLife"); will output space instead of tab.Why?
	//ft_printf("%s%c%c%sLife\n", "yoyoyoyo", '$', '%', "hello");
	ft_printf("Number:\n%d\n", x);
	printf("String address: %p\n", &x);
	return (0);
}


























