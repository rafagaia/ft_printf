/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxf_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:55:47 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/11 22:22:17 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				percent_handle(t_token *fmt_token)
{
	char		*str;
	int			len;

	str = ft_strdup("%");
	if (fmt_token->width)
		str = padding_handle(fmt_token->flag, fmt_token->width, "%");
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int				o_handle(t_token *fmt_token, va_list *vargs)
{
	intmax_t	nbr;
	char		*str;
	char		*tmp;
	int			len;

	if ((fmt_token->length)[0])
		nbr = length_handle(-1, fmt_token->length, vargs);
	else
		nbr = va_arg(*vargs, intmax_t);
	str = ft_itoa_base_unsigned(nbr, 8);
	if (fmt_token->flag == '#')
	{
		tmp = ft_strjoin("0", str);
		ft_strdel(&str);
		str = tmp;
	}
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

int				x_handle_helper(t_token *fmt_token, char *str)
{
	int			i;
	char		*tmp;

	i = -1;
	if (fmt_token->flag == '#')
	{
		tmp = ft_strjoin("0x", str);
		ft_strdel(&str);
		str = tmp;
	}
	if (fmt_token->conversion == 'x')
		ft_putstr(str);
	else
	{
		while (str[++i])
			str[i] = ft_toupper(str[i]);
		ft_putstr(str);
	}
	return ((ft_strlen(str)));
}

int					x_handle(t_token *fmt_token, va_list *vargs)
{
	unsigned int	nbr;
	char			*str;
	int				len;

	if ((fmt_token->length)[0])
		nbr = length_handle(1, fmt_token->length, vargs);
	else
		nbr = va_arg(*vargs, unsigned int);
	str = ft_itoa_base_unsigned(nbr, 16);
	if (fmt_token->width)
		str = padding_handle(fmt_token->flag, fmt_token->width, str);
	len = x_handle_helper(fmt_token, str);
	free(str);
	return (len);
}
