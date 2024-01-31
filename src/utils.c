/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:50:56 by tristan           #+#    #+#             */
/*   Updated: 2024/01/30 11:55:59 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"


int	in_char_set(char c, char *char_set)
{
	int	i;

	i = 0;
	while (char_set[i])
	{
		if (char_set[i] == c)
			return (0);
		i++;
	}
	return (1);
}


int char_set_in_string(char* char_set, char *str){
	int i = 0;

	while (str[i]){
		if (in_char_set(str[i], char_set) != 0)
			return (1);
		i++;
	}
	return (0);
}