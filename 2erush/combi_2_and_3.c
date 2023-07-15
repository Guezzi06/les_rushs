/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi_2_and_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:00:37 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/24 16:44:55 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_prototypes.h"

/* Toutes les combinaisons possibles pour le nombre 2 :
   -> 1 4 2 3   -> 2 4 3 1   -> 3 4 2 1   -> 3 2 1 4
   -> 1 4 3 2   -> 2 1 4 3   -> 3 1 2 4   -> 3 2 4 1
   -> 2 4 1 3   -> 3 4 1 2   -> 3 1 4 2

   Toutes les combinaisons possibles pour le nombre 3 :
   -> 1 2 4 3   -> 1 3 4 2   -> 2 3 1 4
   -> 1 3 2 4   -> 2 3 4 1   -> 2 1 3 4
*/

/*
int	str_is_2_or_3(char **tab, char *str)
{
	int		i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '2')
		{
			combinaisons_number_2(i);
		}
		else if (str[i] == '3')
		{
			combinaisons_number_3(i);
		}
	}
}

int	combinaisons_number_2(char **tab, int i)
{
	if (i <= 6)
	{
		
	}
	else if (i <= 14)
	{

	}
	else if (i <= 22)
	{

	}
	else
	{

	}
}

int	combinaisons_number_3()
{
	if (i <= 6)
	{
		
	}
	else if (i <= 14)
	{

	}
	else if (i <= 22)
	{

	}
	else
	{

	}
}
*/
