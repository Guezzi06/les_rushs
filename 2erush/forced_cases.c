/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forced_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:18:22 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/24 17:26:14 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "all_prototypes.h"

int	boucle_number_4(char **tab, int i, int j, int k)
{
	while (k < 4)
	{
		if (i <= 6)
		{
			if (!(verif_case_number(tab, i, j, k)))
				return (0);
		}
		else if (i <= 14)
		{
			if (!(verif_case_number(tab, i, j, k)))
				return (0);
		}
		else if (i <= 22)
		{
			if (!(verif_case_number(tab, i, j, k)))
				return (0);
		}
		else
		{
			if (!(verif_case_number(tab, i, j, k)))
				return (0);
		}
		k++;
	}
	return (1);
}

int	test_1_face_4(char *str, int i)
{
	if (i <= 6)
	{
		if (str[i + 8] != '1')
			return (0);
	}
	else if (i <= 14)
	{
		if (str[i - 8] != '1')
			return (0);
	}
	else if (i <= 22)
	{
		if (str[i + 8] != '1')
			return (0);
	}
	else
	{
		if (str[i - 8] != '1')
			return (0);
	}
	return (1);
}

int	str_is_4(char **tab, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 31)
	{
		if (str[i] == '4')
		{
			if (!(test_1_face_4(str, i)))
			{
				put_error_message();
				return (0);
			}
			if (!(boucle_number_4(tab, i, j, k)))
				return (0);
			k = 0;
		}
		i += 2;
		j = (i / 2) % 4;
	}
	return (1);
}
