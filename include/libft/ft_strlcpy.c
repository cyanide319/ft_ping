/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:49:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/04/01 14:17:43 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	const size_t	srcn = ft_strlen(src);

	if (srcn + 1 < n)
		ft_memmove(dest, src, srcn + 1);
	else if (n != 0)
	{
		ft_memmove(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (srcn);
}
