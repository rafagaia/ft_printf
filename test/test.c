/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 22:11:05 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/02 12:20:49 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

int			main(void)
{
	printf("1.{%s}\n", 0);
	ft_printf("1.{%s}\n", 0);

	printf("2.%.5c\n", 0);
	ft_printf("2.%.5c\n", 0);
	
	printf("3.%.4d\n", 42);
	ft_printf("3.%.4d\n", 42);
	
	printf("4.%O\n");
	ft_printf("4.%O\n");
	
	printf("5.%+d\n", 42);
	ft_printf("5.%+d\n", 42);
	
	printf("6.%#o\n", 42);
	ft_printf("6.%#o\n", 42);
	
	//printf("7.%ld\n", (long)INT_MAX + 1);
	//printf("8.%ho, %ho\n", 0, USHRT_MAX);

	return (0);
}
