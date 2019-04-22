/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:22:42 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/22 15:29:46 by rgaia            ###   ########.fr       */
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
