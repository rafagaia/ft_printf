/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxXf_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:55:47 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/25 05:56:54 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				o_handle(t_token *fmt_token, va_list *vargs)
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

int				xX_handle(t_token *fmt_token, va_list *vargs)
{
	uintmax_t	nbr;
	char		*str;
	int			len;
	int			i;

	i = -1;
	nbr = va_arg(*vargs, uintmax_t);
	str = ft_itoa_base_unsigned(nbr, 16);
	if (fmt_token->conversion == 'x')
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
