/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f_m_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:04:03 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/31 13:04:07 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_f_m_a.h"
#include "useful_f_p1.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "move_figure.h"
#include "logical.h"

void	log_xor(t_f *borders, t_f *main_field, t_f figure_copy)
{
	logical_xor(borders, borders);
	logical_xor(main_field, &figure_copy);
}

void	move(t_f *figure, t_f figure_copy)
{
	move_down(figure);
	copy_in_struct(&figure_copy, figure);
}

char	*creat_temp(char *t_i, char *str, int quantity)
{
	int i;

	i = 0;
	t_i = malloc(sizeof(char) * (quantity + 1));
	t_i[quantity] = '\0';
	while (i < quantity)
	{
		t_i[i] = str[i];
		++i;
	}
	return (t_i);
}

void	gen_swap(t_gen *gen, char *str)
{
	gen->temp = *gen->p;
	*gen->p = *str;
	*str = gen->temp;
}

void	gen_start_swap(char *p, char *str)
{
	char	temp;

	temp = *p;
	*p = *str;
	*str = temp;
}
