/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 23:14:54 by rgaia             #+#    #+#             */
/*   Updated: 2019/04/25 05:30:24 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	// Known issue: ft_printf("%d\tLife"); will output space instead of tab.Why?
	//ft_printf("ft_printf: c:%c; s:%s; p:%p\n", 'c', "ass", &x);

	ft_printf("ft_printf: %#322.90hhX\n %0100.42lls\n", 0xff, "it works");
	return (0);
}
