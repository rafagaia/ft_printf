/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:07:49 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/17 01:36:40 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	int			len;
	va_list		va;

	len = 0;
	va_start(va, fmt);
	while (*fmt)
	{
		printf("While *fmt: %c\n", *fmt);
		if (*fmt == '%')
			//len += format_handler();
		else
		{
			len += write(1, fmt, 1);
		}
		fmt++;
	}
	//va_end
	return (len);
}




























