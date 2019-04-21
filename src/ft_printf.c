/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:49 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/21 14:22:50 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		format_handler(char **fmt, va_list *vargs)
{
	if (**fmt == 'd')
	{
		*fmt += 1;
		ft_putstr("[handle 'd']");
	}
	return (1);
}

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
			fmt++;
			len += format_handler(&fmt, &vargs);
		}
		else
		{
			len += write(1, fmt, 1);
			fmt++;
		}
	}
	va_end(vargs);
	return (len);
}

int		main(void)
{
	ft_printf("%d Life%d\n", 42);
	return (0);
}


























