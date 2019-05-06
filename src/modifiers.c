/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:05:07 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/06 15:03:37 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** Handles the (l, ll, h, hh) %[length] specifiers for ft_printf
** Applies to following %[conversion] specifiers:
** d (decimal integers),i (integer specifically), u (unsigned decimal int)
** o (octal integers), x, X (hexa int)
*/

uintmax_t		length_handle(int sign, char *modifier, va_list *vargs)
{
	if (sign == -1)
	{
		if (ft_strequ(modifier, "l"))
			return ((signed long int)va_arg(*vargs, intmax_t));
		else if (ft_strequ(modifier, "ll"))
			return ((signed long long int)va_arg(*vargs, intmax_t));
		else if (ft_strequ(modifier, "h"))
			return ((signed short int)va_arg(*vargs, intmax_t));
		else if (ft_strequ(modifier, "hh"))
			return ((signed char)va_arg(*vargs, intmax_t));
	}
	else if (sign == 1)
	{
		if (ft_strequ(modifier, "l"))
			return ((unsigned long int)va_arg(*vargs, intmax_t));
		else if (ft_strequ(modifier, "ll"))
			return ((unsigned long long int)va_arg(*vargs, intmax_t));
		else if (ft_strequ(modifier, "h"))
			return ((unsigned short int)va_arg(*vargs, intmax_t));
		else if (ft_strequ(modifier, "hh"))
			return ((unsigned char)va_arg(*vargs, intmax_t));
	}
	return (sign);
}

void			minus_flag_handler(char *out_str, char *str, int width, char p)
{
	int			i;

	i = ft_strlen(str);
	ft_strcpy(out_str, str);
	while (i < width)
		out_str[i++] = p;
}

/*
** Handles [flags]: 0 pad; ' ' (space) pad; '-' left align; '+' positive number
** All using the [width] value passed in
** If '\0' flag: pads with <space> character by default, <pad> otherwise
** Allocates and returns new formatted string ready to be printed to STDOUT
** (default): right-align (fill pad first)
*/

char			*padding_handle(char flag, int width, char *str)
{
	int			i;
	int			str_len;
	char		pad;
	char		*out_str;

	i = 0;
	str_len = ft_strlen(str);
	pad = ' ';
	if (flag == '0')
		pad = '0';
	if (width <= str_len)
		return (str);
	out_str = ft_strnew(width);
	if (flag == '-')
		minus_flag_handler(out_str, str, width, pad);
	else
	{
		width = width - str_len;
		while (i < width)
			out_str[i++] = pad;
		if (flag == '+')
			out_str[--i] = '+';
		ft_strcat(out_str, str);
	}
	return (out_str);
}
