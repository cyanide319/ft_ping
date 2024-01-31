/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:05:52 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/04/07 12:55:10 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		n;
	size_t		destlen;
	char		*d;
	const char	*s = src;

	n = size;
	d = dest;
	while (n-- && *d)
		d++;
	destlen = d - dest;
	n = size - destlen;
	if (!n)
		return (destlen + ft_strlen(src));
	while (*s)
	{
		if (n > 1)
		{
			*(d++) = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (destlen + (s - src));
}
