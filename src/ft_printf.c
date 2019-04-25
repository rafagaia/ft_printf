/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:49 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/25 05:32:16 by rgaia            ###   ########.fr       */
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

char		get_conversion(char *fmt)
{
	char	c;

	while (*fmt)
	{
		c = *fmt++;
		if ((c == '%') || (c == 'c') || (c == 's') || (c == 'p') || 
			(c == 'd') || (c == 'i') || (c == 'o') || (c == 'u') || 
			(c == 'x') || (c == 'X'))
		{
			return (c);
		}
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

int			get_nbr(char *fmt, char c)
{
	int		i;
	int		j;
	int		nbr_exist;
	char	*nbr;

	i = 0;
	nbr_exist = 0;
	while ((fmt[i] != c))
	{
		j = i;
		if (ft_isdigit(fmt[i]))
		{
			nbr_exist = 1;
			break;
		}
		i++;
	}
	while (ft_isdigit(fmt[i]))
		i++;
	if (nbr_exist == 1)
		nbr = ft_strndup((fmt + j), (i - j));
	else
		return (0);
	nbr_exist = ft_atoi(nbr);
	ft_strdel(&nbr);
	return (nbr_exist);
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
			break;
		}
		else if (*fmt == 'h')
		{
			if (*(fmt + 1) == 'h')
				ft_strcpy(fmt_token->length, "hh");
			else if (*(fmt + 1) == fmt_token->conversion)
				ft_strcpy(fmt_token->length, "h");
			break;
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

	fmt_token->flag = '\0';
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
		fmt_token->precision = get_nbr((fmt + p_index), fmt_token->conversion);
	set_length((fmt + p_index), fmt_token);
	/*printf("Build_token->\nconversion: %c\nflag: %c\nwidth: %d\nprecision: %d\nlength:%s\n", 
			fmt_token->conversion, fmt_token->flag, fmt_token->width, 
			fmt_token->precision, fmt_token->length);*/
	return (1);
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
				ft_putendl("__________");
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






