/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:19:26 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/31 18:46:09 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_prototypes.h"

#define B 9000

char	*dic(char *str)
{
	char	*d;
	int		i;
	int 	v;

	i = 0;
	v = 0;
	d = malloc(sizeof(char) * 54);
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= 32 && str[i] <= 126)
	{
		d[v] = str[i];
		v++;
		i++;
	}
	d[v] = '\0';
	return (d);
}

char	**decomp(int nbr)
{
	int		i;
	int		j;
	char	v;
	char	**chiffre;

	i = 0;
	j = 0;
	chiffre = NULL;
	chiffre = malloc(sizeof(char*) * 13);
	while (j < 8)
	{
		chiffre[j] = malloc(sizeof(char) * 5);
		j++;
	}
	if (nbr / 100 != 0)
	{
		v = (nbr / 100) + 48;
		chiffre[i][0] = v;
		chiffre[i][1] = '\0';
		i++;
		chiffre[i] = "100";
		i++;
	}
	nbr = nbr - (nbr / 100) * 100;
	if (nbr >= 1 && nbr <= 20)
	{
		if (nbr / 10 != 0)
		{
			v = nbr / 10 + 48;
			chiffre[i][0] = v;
			v = nbr % 10 + 48;
			chiffre[i][1] = v;
			chiffre[i][2] = '\0';
			i++;
		}
		else
		{
			v = nbr + 48;
			chiffre[i][0] = v;
			chiffre[i][1] = '\0';
			i++;
		}
	}
	else if ((nbr >= 21) && (nbr % 10 == 0))
	{
		v = nbr / 10 + 48;
		chiffre[i][0] = v;
		chiffre[i][1] = '0';
		chiffre[i][2] = '\0';
		i++;
	}
	else if (nbr != 0)
	{
		v = nbr / 10 + 48;
		chiffre[i][0] = v;
		chiffre[i][1] = '0';
		chiffre[i][2] = '\0';
		i++;
		v = nbr % 10 + 48;
		chiffre[i][0] = v;
		chiffre[i][1] = '\0';
		i++;
	}
	chiffre[i][0] = '\0';
	return (chiffre);
}

int	*ft_decoupe(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	j;
	int	k;
	int	nbr;

	tab = NULL;
	i = 0;
	j = 0; 
	nbr = 0;
	if (argc == 2)
	{
		tab = malloc(sizeof(int) * 8);
		k = ft_strlen(argv[1]) % 3;
		if (k == 1)
			k = 2;
		else if (k == 2)
			k = 1;
		while (i < ft_strlen(argv[1]))
		{
			nbr = nbr * 10 + (argv[1][i] - 48);
			i++;
			k++;
			if (k % 3 == 0)
			{
				tab[j] = nbr;
				nbr = 0;
				j++;
			}
		}
	}
	tab[j] = -1;
	return (tab);
}

int main(int argc, char **argv)
{
	(void)argc;
	int i;
	int j;
	int fd;
	int ret;
	int	*tab;
	char *mot;
	char *illion;
	char **chiffres;
	char *buf;

	fd = open("numbers.dict.es.txt", O_RDONLY);
	illion = NULL;
	illion = malloc(sizeof(char) * 37);
	buf = malloc(sizeof(char) * B + 1);
	fd = open("numbers.dict.fr.txt", O_RDONLY);
	if(fd == -1)
		write(1, "Error\n", 6);
	ret = read(fd, buf, B);
	buf[ret] = '\0';
	tab = ft_decoupe(argc, argv);
	while (tab[i] != - 1)
	{
		j = 0;
		chiffres = decomp(tab[i]);
		while (chiffres[j][0] != '\0')
		{
			mot = dic(ft_strstr(buf, chiffres[j]));
			write(1, mot, ft_strlen(mot));
			write(1, " ", 1);
			if (ft_strcmp(mot, "hundred") == 0 && tab[i] % 100 != 0)
				write(1, "and ", 4);
			j++;
		}
		i++;
		if (tab[i] != - 1 && tab[i - 1] != 0)
		{
			illion[0] = '1';
			j = i;
			while (tab[j] != - 1)
			{
				illion = ft_strcat(illion, "000");
				j++;
			}
			mot = dic(ft_strstr(buf, illion));
			write(1, mot, ft_strlen(mot));
			write(1, ", ", 2);
			illion[1] = '\0';
		}
	}
	free(buf);
	free(tab);
	free(chiffres);
	if(close(fd) == -1)
		write(1, "Error\n", 6);
	return (0);
}
