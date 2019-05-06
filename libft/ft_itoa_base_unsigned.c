/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:06:10 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/06 14:41:06 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_unsigned(uintmax_t n, int base)
{
	uintmax_t		nbr;
	long			len;
	char			*str;

	len = 0;
	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		len++;
		nbr /= base;
	}
	str = ft_strnew(len);
	str[len] = '\0';
	while (n)
	{
		str[--len] = "0123456789abcdef"[n % base];
		n /= base;
	}
	return (str);
}
