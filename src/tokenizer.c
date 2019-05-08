/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:46:36 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/07 15:12:08 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			is_conversion_specifier(char c)
{
	return ((c == '%') || (c == 'c') || (c == 'C') ||
		(c == 's') || (c == 'S') || (c == 'p') ||
		(c == 'd') || (c == 'i') || (c == 'o') ||
		(c == 'u') || (c == 'U') || (c == 'x') || (c == 'X'));
}

char		get_conversion(char *fmt)
{
	char	c;

	while (*fmt)
	{
		c = *fmt++;
		if (is_conversion_specifier(c))
			return (c);
	}
	return ('\0');
}

char		get_flag(char *fmt)
{
	char	c;

	c = *fmt;
	if ((c == '#') || (c == '-') || (c == '+') || (c == ' ') || (c == '0'))
		return (c);
	return ('\0');
}

void		set_length(char *fmt, t_token *fmt_token)
{
	while (ft_isdigit(*fmt))
		fmt++;
	while (*fmt != fmt_token->conversion)
	{
		if (*fmt == 'l')
		{
			if (*(fmt + 1) == 'l')
				ft_strcpy(fmt_token->length, "ll");
			else if (*(fmt + 1) == fmt_token->conversion)
				ft_strcpy(fmt_token->length, "l");
			break ;
		}
		else if (*fmt == 'h')
		{
			if (*(fmt + 1) == 'h')
				ft_strcpy(fmt_token->length, "hh");
			else if (*(fmt + 1) == fmt_token->conversion)
				ft_strcpy(fmt_token->length, "h");
			break ;
		}
		fmt++;
	}
}

/*
** @in: format string, and token struct to be built
** @out: 0: token was not built; 1: token built
*/

int			build_token(char *fmt, t_token *fmt_token)
{
	int		p_index;

	fmt_token->width = -1;
	fmt_token->precision = -1;
	fmt_token->conversion = '\0';
	ft_strclr(fmt_token->length);
	if ((fmt_token->conversion = get_conversion(fmt)) == '\0')
		return (0);
	fmt_token->flag = get_flag(fmt);
	fmt_token->width = get_nbr((fmt + (fmt_token->flag ? 1 : 0)),
								fmt_token->conversion);
	p_index = (fmt_token->flag ? 1 : 0) + (fmt_token->width == 0 ? 0 :
											ft_numdigit(fmt_token->width));
	if (fmt[p_index] == '.')
	{
		fmt_token->precision = get_nbr((fmt + p_index + 1),
				fmt_token->conversion);
	}
	set_length((fmt + p_index), fmt_token);
	return (1);
}
