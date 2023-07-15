/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:07:12 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/24 17:33:34 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "all_prototypes.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	tab = malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		tab[i] = malloc(sizeof(char) * 4);
		i++;
	}
	i = 0;
	if (!(verif_data_user(argc, i, argv[1])))
		return (0);
	init_tab(tab);
	if (!(str_is_4(tab, argv[1])))
		return (0);
	print_tab(tab);
	free(tab);
	return (0);
}
