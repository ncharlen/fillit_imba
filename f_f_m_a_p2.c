/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f_m_a_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:46:41 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/31 14:46:44 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_f_m_a_p2.h"
#include "useful_f_p1.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "move_figure.h"
#include "f_f_m_a.h"
#include "logical.h"
#include "main_algorithm.h"

int		gen_else(t_gg *g_gg, char *str, t_gen *gen_p)
{
	t_f fun_fig;
	t_gg *g_m_f_c;

	g_m_f_c = g_gg;

	gen_p->check_mask |= 1 << (*gen_p->p);
	gen_swap(gen_p, str);
	set_figure(&fun_fig, create_tetro(*str));
	if (se_pos(&fun_fig, g_m_f_c, str))
		return (1);
	gen_swap(gen_p, str);
	return (0);
}

void	set_st(t_s *se_st, int g_s, t_f *figure)
{
	t_s		*se_st_p;

	se_st_p = se_st;
	se_st_p->max_x_f = count_for_max_x(figure);
	se_st_p->max_y_f = count_for_max_y(figure);
	se_st_p->max_x = g_s - se_st_p->max_x_f + 1;
	se_st_p->max_y = g_s - se_st_p->max_y_f + 1;
}

void	se_pos_st_p1(t_gg *g_g, t_xy se_xy, t_f *f, char *str)
{
	t_gg	*g_gg;
	t_f		*f_c;


	g_gg = g_g;
	f_c = f;
	insert_figure(&g_gg->g_m_f, f_c);
	cr_bor(&g_gg->g_b_f, &g_gg->g_m_f);
	put_figure_in_array(*str, se_xy.x, se_xy.y);
}

void	se_pos_st_p2(t_gg *g_g, t_f *f)
{
	t_gg	*g_gg;
	t_f		*f_c;

	g_gg = g_g;
	f_c = f;
	log_xor(&g_gg->g_b_f, &g_gg->g_m_f, *f_c);
	cr_bor(&g_gg->g_b_f, &g_gg->g_m_f);
}

void	set_st_p0(t_m *p, int g_s, t_f *figure)
{
	t_m	*m;

	m = p;
	m->f_p = &m->f_c;
	m->se_st_p = &m->se_st;
	m->se_xy.y = 0;
	set_st(m->se_st_p, g_s, figure);
	copy_in_struct(&m->f_c, figure);
}
