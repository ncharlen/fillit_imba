/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_print_final_result.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:12:00 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:12:01 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_print_final_result.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "useful_f_p1.h"

t_f g_for_fill;

void	fill_array(char *temp_inital, char *str, int quantity)
{
	int i;

	i = 0;
	temp_inital = malloc(sizeof(char) * (quantity + 1));
	temp_inital[quantity] = '\0';
	while (i < quantity)
	{
		temp_inital[i] = str[i];
		++i;
	}
}

void	fill_bigarray(int g_s, char d2a[][g_s])
{
	int i;
	int j;

	i = 0;
	while (i < g_s)
	{
		j = 0;
		while (j < g_s)
		{
			d2a[i][j] = '.';
			++j;
		}
		d2a[i][g_s] = '\n';
		++i;
	}
	d2a[g_s][g_s] = '\n';
}

void	fill_f_l(int g_s, uint16_t *a, char d2a[][g_s])
{
	int		k;
	int32_t i;
	int32_t j;

	j = 0;
	while (*a)
	{
		i = 0;
		set_figure(&g_for_fill, create_tetro(*a & 31));
		while (i < 8)
		{
			j = 0;
			while (j < 8)
			{
				if (g_for_fill.sqrt0 & 1)
					d2a[i + ((*a >> 9) & 15)][j + ((*a >> 5) & 15)] = 'A' + k;
				g_for_fill.sqrt0 >>= 1;
				++j;
			}
			++i;
		}
		++a;
		++k;
	}
}

void	print_bigarray(int g_s, char d2a[][g_s])
{
	int i;
	int j;

	i = 0;
	while (i < g_s)
	{
		j = 0;
		while (j < g_s)
		{
			printf("%c", d2a[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

void	check_array(char *a, uint16_t *for_print, int quantity)
{
	uint16_t	*temp;
	int			i;
	int			k;

	i = 0;
	temp = create_copy_a(temp, quantity, for_print);
	while (i < quantity)
	{
		k = 0;
		while (k < quantity)
		{
			if (a[i] == (temp[k] & 0x1F))
			{
				for_print[i] = temp[k];
				temp[k] = 0;
				break ;
			}
			++k;
		}
		++i;
	}
	free(temp);
}
