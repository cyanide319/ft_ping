/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:01:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/04/08 18:28:59 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_count(char const *src, char sep)
{
	int	count;

	count = 0;
	if (!src)
		return (0);
	while (*src)
	{
		while (*src == sep)
			src++;
		if (*src != sep && *src)
			count++;
		while (*src != sep && *src)
			src++;
	}
	return (count);
}

char	**ft_split(char const *src, char sep)
{
	char		**splitd;
	int			i;
	const int	words = ft_count(src, sep);
	int			len;

	i = 0;
	if (!src)
		return (NULL);
	splitd = ft_calloc(sizeof(char *), words + 1);
	if (!splitd)
		return (NULL);
	while (i < words)
	{
		while (*src && *src == sep)
			src++;
		if (ft_strchr(src, sep))
			len = ft_strchr(src, sep) - src;
		else
			len = ft_strlen(src);
		splitd[i] = ft_substr(src, 0, len);
		src += len;
		i++;
	}
	return (splitd);
}
