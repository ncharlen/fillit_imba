/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f_m_a_p4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:46:41 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/31 14:46:44 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_f_m_a_p4.h"
#include "f_f_m_a_p3.h"
#include "f_f_m_a_p2.h"
#include "useful_f_p1.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "move_figure.h"
#include "f_f_m_a.h"
#include "logical.h"
#include "main_algorithm.h"
/*
void	set_gen_st(t_gen_st *p, char *str, int quantity)
{
	t_gen_st *st;
	uint16_t	*g;

	g = extern g_f_p_a;
	st = p;
	st->t_i = creat_temp(st->t_i, str, quantity);
	st->check_mask = 0;
	st->arg = 0;
	extern g_f_p_a = malloc(sizeof(uint16_t) * (quantity + 1));
	extern g_f_p_a[quantity] = '\0';
}*/