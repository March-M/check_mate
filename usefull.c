/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:23:31 by exam              #+#    #+#             */
/*   Updated: 2018/01/02 12:04:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int	ft_strallchr(char *str, char c)
{
	int col;
	int res;

	col = 0;
	res = 0;
	while (str[col] != '\0')
	{
		if (str[col] == c)
			res++;
	col++;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	int res;

	res = 0;
	while (str[res] != '\0')
		res++;
	return (res);
}
