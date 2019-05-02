/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:05:07 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/28 18:10:50 by rgaia            ###   ########.fr       */
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





/*
** Handles [flags]: 0 pad; ' ' (space) pad; '-' left align; '+' positive number
** All using the [width] value passed in
** If '\0' flag: pads with <space> character by default, <pad> otherwise
** Allocates and returns new formatted string ready to be printed to STDOUT
*/
char			*padding_handle(char flag, int width, char *str)
{
	int			i;
	int			str_len;
	int			out_len;
	char		pad;
	char		*out_str;

//	printf("Padding_handle:flag:%c,width:%d,str:%s\n", flag, width, str);
	i = 0;
	pad = ' '; //(default) padding for when only width is passed
	str_len = ft_strlen(str);
	if (width <= str_len)
		return (str);
	out_len = width;
	if (flag == '0')
		pad = '0';
	if (! (out_str = ft_strnew(out_len)))
		ft_puterror("Bad padding strnew", -1);
	//if left-align, store str first, then zero's or space
	if (flag == '-')
	{
		ft_strcpy(out_str, str);
		i = ft_strlen(str);
		while (i < width)
			out_str[i++] = pad;
	}
	else //(default): right-align (fill pad first)
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

