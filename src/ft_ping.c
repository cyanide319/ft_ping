/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:22:04 by tristan           #+#    #+#             */
/*   Updated: 2024/02/04 18:02:19 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"


struct vars glob_vars;



void	print_h(int flag, char* str){
	if (flag != 0){
		//for (int i = 0; i < flag; i++)
		//	str++;
		fprintf(stderr, "ping: invalid option --  '%c' \n\n", str[flag]);
	}
	printf("Usage\n  ping [options] <destination>\n\n");
	printf("Options:\n");
	printf("  -h                 print help and exit\n");
	printf("  -v                 verbose output\n");
}

void parse_variables(int argc, char** argv){
	for(int i = 1; i < argc; i++){
		if (argv[i][0] == '-'){
			for(int j = 1; argv[i][j] != '\0'; j++){
				if (argv[i][j] == 'h'){
					print_h(0, NULL);
					exit(EXIT_SUCCESS);
				}
				if (argv[i][j] != 'v'){
					print_h(j, argv[i]);
					exit(EXIT_SUCCESS);
				}
				else
					glob_vars.verbose = 1;
			}
		}
		else{
			if(char_set_in_string("123456789.", argv[i]) == 1){
				glob_vars.ip = argv[i];
				glob_vars.domain = NULL;
			}
			else{
				glob_vars.domain = argv[i];
				glob_vars.ip = NULL;
			}
			
		}
	}
}

int main(int argc, char** argv){
	if (argc < 2){
		fprintf(stderr, "ping: usage error: %s", "Destination address required\n");
		exit(EXIT_FAILURE);
	}

	glob_vars.domain = NULL;
	glob_vars.ip = NULL;
	glob_vars.verbose = 0;

	parse_variables(argc, argv);

	if (glob_vars.ip != NULL){
		printf(glob_vars.ip);
		printf(";");}
	if (glob_vars.domain != NULL){
		printf(glob_vars.domain);
		printf(";");}

	int socketfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (socketfd == -1){
		fprintf(stderr, "ping: error: %s", "Failed to create socket\n");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in dest_address;
	ft_memset(&dest_address, 0, sizeof(dest_address));
	dest_address.sin_family = AF_INET;
	if (glob_vars.ip != NULL){
		if (inet_pton(AF_INET, glob_vars.ip, &dest_address.sin_addr) <= 0){
			fprintf(stderr, "ping: %s %s", glob_vars.ip ,": Name or service not known\n");
			exit(EXIT_FAILURE);
		}
	}
	exit(0);
}
