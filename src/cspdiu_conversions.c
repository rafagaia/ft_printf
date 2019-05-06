/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiu_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:56:17 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/06 15:10:20 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				c_handle(t_token *fmt_token, va_list *vargs)
{
	char		*str;

	str = ft_strnew(1);
	str[0] = (char)va_arg(*vargs, int);
	if (fmt_token->width)
		str = padding_handle(fmt_token->flag, fmt_token->width, str);
	if (fmt_token->precision)
		str = padding_handle('0', fmt_token->precision, str);
	ft_putchar(*str);
	ft_strdel(&str);
	return (1);
}

int				s_handle(t_token *fmt_token, va_list *vargs)
{
	char		*str;
	int			len;

	str = va_arg(*vargs, char*);
	if (!str)
	{
		ft_putstr("(null)");
		return (0);
	}
	if (fmt_token->width)
		str = padding_handle(fmt_token->flag, fmt_token->width, str);
	if (fmt_token->precision)
		str = padding_handle('0', fmt_token->precision, str);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

int				p_handle(t_token *fmt_token, va_list *vargs)
{
	uintmax_t	addr;
	char		*str;
	int			len;

	addr = va_arg(*vargs, uintmax_t);
	str = ft_strnew(sizeof(addr) + 2);
	ft_strcpy(str, "0x");
	ft_strcat(str, ft_itoa_base_unsigned(addr, 16));
	if (fmt_token->width)
		str = padding_handle(fmt_token->flag, fmt_token->width, str);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

/*
**	Handles length -> width -> precision
*/

intmax_t		di_handle(t_token *fmt_token, va_list *vargs)
{
	intmax_t	nbr;
	char		*str;

	if ((fmt_token->length)[0])
		nbr = (int)length_handle(-1, fmt_token->length, vargs);
	else
		nbr = (int)va_arg(*vargs, intmax_t);
	str = ft_itoa(nbr);
	if (fmt_token->width)
		str = padding_handle(fmt_token->flag, fmt_token->width, str);
	else if (fmt_token->flag == '+')
		str = padding_handle('+', (1 + ft_strlen(str)), str);
	if (fmt_token->precision)
		str = padding_handle('0', fmt_token->precision, str);
	ft_putstr(str);
	nbr = ft_strlen(str);
	ft_strdel(&str);
	return (nbr);
}

uintmax_t		u_handle(t_token *fmt_token, va_list *vargs)
{
	uintmax_t	nbr;
	char		*str;
	int			len;

	if ((fmt_token->length)[0])
		nbr = length_handle(1, fmt_token->length, vargs);
	else
		nbr = (unsigned int)va_arg(*vargs, uintmax_t);
	str = ft_itoa_base_unsigned(nbr, 10);
	if (fmt_token->width)
		str = padding_handle(fmt_token->flag, fmt_token->width, str);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}
