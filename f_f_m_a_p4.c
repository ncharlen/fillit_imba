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
#include "fill_print_final_result.h"
#include "main_a_sup.h"

extern uint16_t	*g_f_p_a;
extern int 		g_flag;


void	set_gen_st(t_ms *q, char *str, int quantity)
{
	t_ms *st;
	extern uint16_t *g_f_p_a;

	st = q;
	st->p = str;
	st->st = &st->st_np;
	st->st->t_i = creat_temp(st->st->t_i, str, quantity);
	st->st->check_mask = 0;
	st->st->arg = 0;
	g_f_p_a = malloc(sizeof(uint16_t) * (quantity + 1));
	g_f_p_a[quantity] = '\0';
}

void	set_gen_p0(t_ms *q, char *str, t_gg *g_g)
{
	t_gg	*g_gg;

	g_gg = g_g;
	if ((q->st->check_mask & (1 << (*q->p))) == 0)
	{
		q->st->check_mask |= 1 << (*q->p);
		gen_start_swap(q->p, str);
		set_figure(&q->fun_fig, create_tetro(*str));
		q->st->arg = se_pos_st(&q->fun_fig, g_gg, str);
		gen_start_swap(q->p, str);
	}
}

int 	set_gen_arg(t_ms *q, char d2garray[][g_s], int quantity, char *str)
{
	if (q->st->arg == 1)
	{
		check_array(q->st->t_i, g_f_p_a, quantity);
		fill_bigarray(g_s, d2garray);
		fill_f_l(g_s, g_f_p_a, d2garray);
		print_bigarray(g_s, d2garray);
		free(g_f_p_a);
		free(q->st->t_i);
		return (1);
	}
	else
	{
		g_flag = 1;
		free(g_f_p_a);
		free(q->st->t_i);
		generate_start(str, quantity);
	}
	return (0);
}