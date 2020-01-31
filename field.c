/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:11:28 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:11:31 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "move_figure.h"
#include "useful_f_p1.h"
#include "logical.h"

void	cr_bor(t_f *borders_field, t_f *main_field)
{
	t_f mask_field;

	copy_in_struct(&mask_field, main_field);
	logical_or(borders_field, &mask_field);
	m_up_right(&mask_field);
	l_c(borders_field, main_field, &mask_field);
	move_down(&mask_field);
	move_left(&mask_field);
	l_c(borders_field, main_field, &mask_field);
	move_up(&mask_field);
	l_c(borders_field, main_field, &mask_field);
	move_up(&mask_field);
	move_left(&mask_field);
	l_c(borders_field, main_field, &mask_field);
	move_left(&mask_field);
	l_c(borders_field, main_field, &mask_field);
	move_right(&mask_field);
	l_c(borders_field, main_field, &mask_field);
	move_down(&mask_field);
	l_c(borders_field, main_field, &mask_field);
	move_right(&mask_field);
	move_down(&mask_field);
	logical_or(borders_field, &mask_field);
	logical_xor(borders_field, main_field);
}

int		c_c(t_f *p_one, t_f *p_two)
{
	return ((p_one->sqrt0 & p_two->sqrt0) || (p_one->sqrt1 & p_two->sqrt1) ||
			(p_one->sqrt2 & p_two->sqrt2) || (p_one->sqrt3 & p_two->sqrt3));
}

void	insert_figure(t_f *main_field, t_f *figure)
{
	logical_or(main_field, figure);
}

int8_t	count_for_max_x(t_f *borders_field)
{
	t_f		border_copy;
	t_f		x_max_check;
	int8_t	count_x;
	int		i;

	i = 0;
	count_x = 0;
	set_x_max(&x_max_check);
	copy_in_struct(&border_copy, borders_field);
	while (i < 8)
	{
		if (c_c(&border_copy, &x_max_check))
			++count_x;
		++i;
		move_left(&border_copy);
	}
	return (count_x);
}

int8_t	count_for_max_y(t_f *borders_field)
{
	t_f		border_copy;
	t_f		y_max_check;
	int8_t	count_y;
	int		i;

	i = 0;
	count_y = 0;
	set_y_max(&y_max_check);
	copy_in_struct(&border_copy, borders_field);
	while (i < 8)
	{
		if (c_c(&border_copy, &y_max_check))
			++count_y;
		++i;
		move_up(&border_copy);
	}
	return (count_y);
}
