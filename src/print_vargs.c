/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:58:26 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/20 19:37:16 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../include/libft.h"

int		print_vargs(char *format, ...)
{
	va_list	vargs;
	char	*buffer;
	char	*str;
	int		fmt_len;
	int		i;

	i = -1;
	fmt_len = ft_strlen(format);
	buffer = ft_strnew(fmt_len);
	ft_putnbr(fmt_len);
	ft_putstr("\n");
	va_start (vargs, format);
	while (format[++i])
		buffer[i] = format[i];
	ft_putendl(buffer);
	
	str = ft_strdup(va_arg(vargs, char*));
	ft_putendl(str);
	free(str);
	
	i = va_arg(vargs, int);
	ft_putendl(ft_itoa(i));

	va_end (vargs);
	return (fmt_len);
}

int		main(void)
{
	printf("\nThe Return Length is: %d\n",
			print_vargs("This is the printf string",
			"second (...) varg",
			3)
		  );
	return (0);
}
