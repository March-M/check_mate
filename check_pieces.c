/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 11:06:13 by exam              #+#    #+#             */
/*   Updated: 2018/01/02 14:25:58 by mgaschet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"
#include <stdio.h>

static int	have_king_diag(int **map, int line, int col, int l_c, int c_c, int nbline)
{
	while (line >=0 && line < nbline && col >= 0 && col < nbline)
	{
		if (map[line][col] == K_)
			return (1);
		line = (l_c == 1) ? line + 1 : line - 1;
		col = (c_c == 1) ? col + 1 : col - 1;
	}
	return (0);
}

static int	have_king_line(int **map, int line, int col, int l_c, int c_c, int nbline)
{
	while (line >=0 && line < nbline && col >= 0 && col < nbline)
	{
		if (map[line][col] == K_)
			return (1);
		line = (l_c == 1 && c_c == -1) ? line + 1 : line;
		line = (l_c == 0 && c_c == -1) ? line - 1 : line;
		col = (c_c == 1 && l_c == -1) ? col + 1 : col;
		col = (c_c == 0 && l_c == -1) ? col - 1 : col;
	}
	return (0);
}

int			check_pawn(int **map, int line, int col, int nbline)
{

	if((line - 1) >= 0)
	{
		if ((col + 1) < nbline && map[line - 1][col + 1] == K_)
			return(1);
		if ((col - 1) >= 0 && map[line - 1][col - 1] == K_)
			return (1);
	}
	return (0);
}

int			check_bishop(int **map, int line, int col, int nbline)
{
	int res;

	res = 0;
	res = have_king_diag(map, line, col, 1, 1, nbline);
	if (res == 0)
		res = have_king_diag(map, line, col, 1, 0, nbline);
	if (res == 0)
		res = have_king_diag(map, line, col, 0, 0, nbline);
	if (res == 0)
		res = have_king_diag(map, line, col, 0, 1, nbline);
	return (res);
}

int			check_rook(int **map, int line, int col, int nbline)
{
	int res;

	res = 0;
	res = have_king_line(map, line, col, 1, -1, nbline);
	if (res == 0)
		res = have_king_line(map, line, col, 0, -1, nbline);
	if (res == 0)
		res = have_king_line(map, line, col, -1, 1, nbline);
	if (res == 0)
		res = have_king_line(map, line, col, -1, 0, nbline);
	return (res);
}

int			check_queen(int **map, int line, int col, int nbline)
{
	int res;
	
	res = 0;
	res = check_bishop(map, line, col, nbline);
	if (res == 0)
		res = check_rook(map, line, col, nbline);
	return (res);
}
