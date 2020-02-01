/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:12:16 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:12:18 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "fill_print_final_result.h"
#include "move_figure.h"
#include "f_f_m_a.h"
#include "f_f_m_a_p2.h"
#include "f_f_m_a_p3.h"
#include "logical.h"
#include "f_f_m_a_p4.h"
#include "main_a_sup.h"

t_gg		g_gg;

int			g_s = 0;
int			g_counter = 0;
uint16_t	*g_f_p_a;

void	put_figure_in_array(char index, u_int8_t x, u_int8_t y)
{
	g_f_p_a[g_counter] = index + (x << 5) + (y << 9);
	++g_counter;
}

int		se_pos_st(t_f *figure, t_gg *g_gg, char *str)
{
	t_m		m;
	t_m		*p;

	p = &m;
	set_st_p0(p, g_s, figure);
	if (str[1])
	{
		while (p->se_xy.y < p->se_st_p->max_y)
		{
			p->se_xy.x = 0;
			while (p->se_xy.x < p->se_st_p->max_x)
			{
				se_pos_st_p1(g_gg, p->se_xy, &p->f_c, str);
				if (generate(str + 1))
					return (1);
				--g_counter;
				se_pos_st_p2(g_gg, &p->f_c);
				se_pos_d(p, figure);
			}
			se_pos_m(p, figure);
		}
	}
	return (0);
}

int		se_pos(t_f *figure, t_gg *g_gg, char *str)
{
	t_m		m;
	t_m		*p;

	p = &m;
	set_st_p0(p, g_s, figure);
	if (str[1])
	{
		while (p->se_xy.y < p->se_st.max_y)
		{
			p->se_xy.x = 0;
			while (p->se_xy.x < p->se_st.max_x)
			{
				if (c_c(&p->f_c, &g_gg->g_b_f) && !c_c(&p->f_c, &g_gg->g_m_f))
				{
					se_pos_st_p1(g_gg, p->se_xy, &p->f_c, str);
					if (generate(str + 1))
						return (1);
					--g_counter;
					se_pos_st_p2(g_gg, &p->f_c);
				}
				se_pos_d(p, figure);
			}
			se_pos_m(p, figure);
		}
	}
	return (0);
}

int		s_p_e(t_f *figure, t_gg *g_gg, char *str)
{
	t_m2	m2;
	t_m2	*p;

	p = &m2;
	set_s_p_e(p, g_s, g_gg, figure);
	while (p->se_xy.y < p->e.max_y)
	{
		p->se_xy.x = 0;
		while (p->se_xy.x < p->e.max_x)
		{
			if (c_c(&p->f_c, &g_gg->g_b_f) && !c_c(&p->f_c, &g_gg->g_m_f))
			{
				insert_figure(&g_gg->g_m_f, &p->f_c);
				cr_bor(&g_gg->g_b_f, &g_gg->g_m_f);
				put_figure_in_array(*str, p->se_xy.x, p->se_xy.y);

				copy_in_struct(&g_gg->g_o_v, &g_gg->g_m_f);
				log_xor(&g_gg->g_b_f, &g_gg->g_m_f, p->f_c);
				cr_bor(&g_gg->g_b_f, &g_gg->g_m_f);
				return (1);
			}
			se_pos_d2(p, figure);
		}
		se_pos_m2(p, figure);
	}
	return (0);
}



int		generate(char *str)
{
	t_f		fun_fig;
	t_gen	gen;
	t_gen	*gen_p;

	gen_p = &gen;
	gen_p->check_mask = 0;
	if (str[1])
	{
		gen_p->p = str;
		while (*gen_p->p)
		{
			if ((gen_p->check_mask & (1 << (*gen_p->p))) == 0)
				if (gen_else(&g_gg, str, gen_p))
					return (1);
			++gen_p->p;
		}
	}
	else
	{
		set_figure(&fun_fig, create_tetro(*str));
		if (s_p_e(&fun_fig, &g_gg, str))
			return (1);
	}
	return (0);
}
