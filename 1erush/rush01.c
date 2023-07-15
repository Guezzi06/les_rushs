/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:00:47 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/16 17:13:49 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c);

void	first_line(int x, int i, int j);

void	inter(int x, int y, int i, int j);

void	last_line(int x, int y, int i, int j);

void	rush(int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (x > 0 && y > 0)
	{
		while (i < y)
		{
			first_line(x, i, j);
			inter(x, y, i, j);
			last_line(x, y, i, j);
			j = 0;
			i++;
		}
	}
}

void	first_line(int x, int i, int j)
{
	if (i == 0)
	{
		while (j < x)
		{
			if (j == 0)
				putchar('/');
			else if (j > 0 && j < x - 1)
				putchar('*');
			else
				putchar('\\');
			j++;
		}
		putchar('\n');
	}
}

void	inter(int x, int y, int i, int j)
{
	if (i > 0 && i < y - 1)
	{
		while (j < x)
		{
			if (j == 0 || j == x - 1)
				putchar('*');
			else
				putchar(' ');
			j++;
		}
		putchar('\n');
	}
}

void	last_line(int x, int y, int i, int j)
{
	if (i == y - 1 && y != 1)
	{
		while (j < x)
		{
			if (j == 0)
				putchar('\\');
			else if (j > 0 && j < x - 1)
				putchar('*');
			else
				putchar('/');
			j++;
		}
		putchar('\n');
	}
}
