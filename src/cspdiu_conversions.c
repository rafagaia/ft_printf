/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiu_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:56:17 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/25 05:57:25 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			c_handle(t_token *fmt_token, va_list *vargs)
{
	char	c;

	c = (char)va_arg(*vargs, int);
	ft_putchar(c);
	return (1);
}

int			s_handle(t_token *fmt_token, va_list *vargs)
{
	char	*str;

	str = va_arg(*vargs, char*);
	ft_putstr(str);
	return (ft_strlen(str));
}

int				p_handle(t_token *fmt_token, va_list *vargs)
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

int				di_handle(t_token *fmt_token, va_list *vargs)
{
	long long	nbr;

	nbr = va_arg(*vargs, long long);
	ft_putnbr(nbr);
	return (ft_numdigit(nbr));
}

int				u_handle(t_token *fmt_token, va_list *vargs)
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

