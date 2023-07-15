/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:28:45 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/24 17:33:13 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "all_prototypes.h"

// Verification Entree donnees utilisateur
int	verif_data_user(int argc, int i, char *str)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (str[i + 1] != '\0')
	{
		if (!(str[i] >= '1' && str[i] <= '4') || str[i + 1] != ' ')
		{
			if (str[i + 1] != '\0')
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		i += 2;
	}
	if (i + 1 != 31 || !(str[30] >= '1' && str[30] <= '4'))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	put_error_message(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	verif_case_number(char **tab, int i, int j, int k)
{
	int		v;

	v = 1;
	if (i <= 6)
		tab[k][j] = '1' + k;
	else if (i > 6 && i <= 14)
	{
		if (tab[3 - k][j] != '0' && tab[3 - k][j] != '1' + k)
			v = put_error_message();
		tab[3 - k][j] = '1' + k;
	}
	else if (i > 14 && i <= 22)
	{
		if (tab[j][k] != '0' && tab[j][k] != '1' + k)
			v = put_error_message();
		tab[j][k] = '1' + k;
	}
	else
	{
		if (tab[j][3 - k] != '0' && tab[j][3 - k] != '1' + k)
			v = put_error_message();
		tab[j][3 - k] = '1' + k;
	}
	return (v);
}
