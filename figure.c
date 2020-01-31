/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:11:43 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:11:45 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "move_figure.h"
#include "logical.h"

const		uint32_t g_tetro[4][8] = {
	{0x0, 0x303, 0xF, 0x603, 0x306, 0x407, 0x107, 0x207},
	{0x0, 0x303, 0x01010101, 0x10302, 0x20301, 0x30202, 0x20203, 0x20302},
	{0x0, 0x303, 0xF, 0x603, 0x306, 0x701, 0x704, 0x702},
	{0x0, 0x303, 0x1010101, 0x10302, 0x20301, 0x10103, 0x30101, 0x10301}
};

void		*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

uint64_t	create_tetro(int index)
{
	return (g_tetro[index >> 3][index & 7]);
}

int			set_and_check_figure(t_f *figure, int t_figure)
{
	t_f max_x;
	t_f max_y;

	set_x_max(&max_x);
	set_y_max(&max_y);
	set_figure(figure, t_figure);
	while (!c_c(&max_y, figure))
		move_up(figure);
	while (!c_c(&max_x, figure))
		move_left(figure);
	if ((t_figure = seek_figure(figure->sqrt0)) == -1)
		return (-1);
	return (t_figure);
}

int			seek_figure(int figure)
{
	int i;
	int k;

	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 8)
		{
			if (g_tetro[i][k] == figure)
				return ((i << 3) + k);
			++k;
		}
		++i;
	}
	return (-1);
}

void		set_figure(t_f *p, uint32_t tetro)
{
	p->sqrt0 = tetro;
	p->sqrt1 = 0;
	p->sqrt2 = 0;
	p->sqrt3 = 0;
}
