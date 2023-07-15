/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:32:21 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/24 16:11:13 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "all_prototypes.h"

void	init_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i != 4)
	{
		tab[i][j] = '0';
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
}

void	print_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i != 4)
	{
		write(1, &tab[i][j], 1);
		write(1, " ", 1);
		j++;
		if (j % 4 == 0)
		{
			j = 0;
			i++;
			write(1, "\n", 1);
		}
	}
}
