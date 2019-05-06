/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:37:52 by rgaia             #+#    #+#             */
/*   Updated: 2019/05/06 14:45:17 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	while ((*str1 || *str2) && n--)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_length;

	needle_length = ft_strlen(needle);
	if (needle_length == 0)
		return ((char*)haystack);
	while (*haystack && needle_length <= len)
	{
		if (*needle == *haystack)
		{
			if (ft_strncmp(haystack, needle, needle_length) == 0)
				return ((char*)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
