/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 23:14:54 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/11 22:26:49 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	test_conversion_specifiers(void)
{
	int		x;
	char	c;
	char	*str;

	x = 42;
	c = '@';
	str = ft_strdup("42Life");
	ft_printf("[FT]\nchar:%c\nstring:%s\npointer:%p\ndecimal:%d\ninteger:%i\n\
octal:%o\nunsigned:%u\nhex:%x\nHEX:%X\n", c, str, &x, x, x, x, x, 0xff, 0xff);
	printf("[STD]\nchar:%c\nstring:%s\npointer:%p\ndecimal:%d\ninteger:%i\n\
octal:%o\nunsigned:%u\nhex:%x\nHEX:%X\n", c, str, &x, x, x, x, x, 0xff, 0xff);
	ft_strdel(&str);
}

void		test_padding(void)
{
	int		ft_len;
	int		std_len;
	
	std_len = printf("[std] Hello:%-8d:\n", 42);
	ft_len = ft_printf("[ft]  Hello:%-8d:\n", 42);
	if (std_len != ft_len)
		printf("Bad ft_printf return len\n");
	std_len = printf("[std] Hello:%08d:\n", 42);
	ft_len = ft_printf("[ft]  Hello:%08d:\n", 42);
	if (std_len != ft_len)
		printf("Bad ft_printf return len\n");
	std_len = printf("[std] :%+8d:\n", 42);
	ft_len = ft_printf("[ft]  :%+8d:\n", 42);
	if (std_len != ft_len)
		printf("Bad ft_printf return len\n");
	std_len = printf("[std] Hello:%+2d:\n", 42);
	ft_len = ft_printf("[ft]  Hello:%+2d:\n", 42);
	if (std_len != ft_len)
		printf("Bad ft_printf return len\n");
}

/*
** Known issues:
**	1. ft_printf("%d\tLife", 42); will output space instead of tab.Why?
**	2.
*/

/*
**	Tests following "unit" sections of our ft_printf implementation:
**		1.	Tokenization "*fmt" elements following STDIO.h Syntax Specifier
**			Convention:	%[flags][width][precision][length]<conversion> 
**		2.	Test each Token individually
**		3.	Integrate in Combinations of 2
**		4.	Integrate in Combinations of 3
*/
int		main(void)
{

	//printf("Test2: {individual} <conversion> specifier Tests:\n");
	//test_conversion_specifiers();
	//test_padding();
	
	printf("Basic tests ---------------------------\n");
	printf("%x", -42)
	ft_printf("%x", -42)

	printf("Precision tests ------------------------------------\n");
	
	return (0);
}
