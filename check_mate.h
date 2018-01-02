/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:06:32 by exam              #+#    #+#             */
/*   Updated: 2018/01/02 14:24:39 by mgaschet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define P_ 2 //Id du pion
#define B_ 3 //Id du fou
#define R_ 4 //Id de la tour
#define Q_ 5 //Id de la reine
#define K_ 6 //Id du roi
#define N_ 1 //Id des case vide

#include <unistd.h>
#include <stdlib.h>

int			ft_strlen(char *str);
int			ft_strallchr(char *str, char c);

int			check_pawn(int **map, int line, int col, int nbline);
int			check_bishop(int **map, int line, int col, int nbline);
int			check_rook(int **map, int line, int col, int nbline);
int			check_queen(int **map, int line, int col, int nbline);
int			check_map(int **map);
void		dbg_print_map(int **map, int nbline);
int			king_check(int **map, int nbline);
