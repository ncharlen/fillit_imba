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

void	set_gen_st(t_ms *p, char *str, int quantity)
{
	t_ms *st;
	extern uint16_t *g_f_p_a;

	st = p;
	st->p = str;
	st->st = &st->st_np;
	st->st->t_i = creat_temp(p->st->t_i, str, quantity);
	st->st->check_mask = 0;
	st->st->arg = 0;
	g_f_p_a = malloc(sizeof(uint16_t) * (quantity + 1));
	g_f_p_a[quantity] = '\0';
}

