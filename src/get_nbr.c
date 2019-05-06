/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:42:18 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/06 15:42:58 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			get_nbr_helper(char *fmt, char c, int *i_, int *j_)
{
	int		i;
	int		j;
	int		nbr_exist;

	i = *i_;
	j = *j_;
	nbr_exist = 0;
	while ((fmt[i] != c) && (fmt[i] != '.'))
	{
		j = i;
		if (ft_isdigit(fmt[i]))
		{
			nbr_exist = 1;
			break ;
		}
		i++;
	}
	return (nbr_exist);
}

int			get_nbr(char *fmt, char c)
{
	int		i;
	int		j;
	int		nbr_exist;
	char	*nbr;

	i = 0;
	j = 0;
	nbr_exist = get_nbr_helper(fmt, c, &i, &j);
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
