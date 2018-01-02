/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:04:28 by exam              #+#    #+#             */
/*   Updated: 2018/01/02 14:26:24 by mgaschet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

static int	validate_map(int ac, char **av)
{
	int	king;
	int count_line;
	int count_col;

	count_line = 1;
	king = 0;
	while (count_line < ac)
	{
		count_col = ft_strlen(av[count_line]);
		if (count_col != (ac - 1))
			return (0);
		king = king + (ft_strallchr(av[count_line], 'K'));
		if (king > 1)
			return (0);
		count_line++;
	}
	return (1);
}

static int	get_piece(char piece)
{
	if (piece == 'P')
		return (P_);
	if (piece == 'B')
		return (B_);
	if (piece == 'R')
		return (R_);
	if (piece == 'Q')
		return (Q_);
	if (piece == 'K')
		return (K_);
	return (N_);
}

static int	**gen_map(int nbline, char **av)
{
	int line;
	int col;
	int **res;
	
	line = 1;
	res = (int **)malloc(sizeof(int *) * (unsigned long)nbline);

	while (line <= nbline)
	{
		col = 0;
		res[line - 1] = (int *)malloc(sizeof(int) * (unsigned long)nbline);
		while (col < nbline)
		{
			res[line - 1][col] = get_piece(av[line][col]);
			col++;
		}
		line++;
	}
	return (res);
}

int			king_check(int **map, int nbline)
{
	int line;
	int col;
	int res;

	line = 0;
	res = 0;
	while (line < nbline)
	{
		col = 0;
		while (col < nbline)
		{
			if (map[line][col] == P_ && res == 0)
				res = check_pawn(map, line, col, nbline);
			if (map[line][col] == B_ && res == 0)
				res = check_bishop(map, line, col, nbline);
			if (map[line][col] == R_ && res == 0)
				res = check_rook(map, line, col, nbline);
			if (map[line][col] == Q_ && res == 0)
				res = check_queen(map, line, col, nbline);
			if (res != 0)
				return (1);
			col++;
		}
		line++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	int **map;
	int result;
	int nbline;
	
	if (validate_map(ac, av) && ac > 1)
	{
		nbline = (int)(ac - 1);
		map = gen_map(nbline, av);
		result = king_check(map, (int)(ac - 1));

		if (result != 0)
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
}
