/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:24:00 by tristan           #+#    #+#             */
/*   Updated: 2024/02/04 17:45:18 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
#define FT_PING_H

#include "./libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
//#include <>

struct vars	{
	int		verbose;
	char	*ip;
	char	*domain;
	const char *IP;
};

//utils
int	in_char_set(char c, char *char_set);
int char_set_in_string(char* char_set, char *str);


#endif