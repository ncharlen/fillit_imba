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
#include "logical.h"

t_f			g_m_f;
t_f			g_b_f;
t_f			g_o_v;

int			g_s = 0;
int			g_counter;
int			g_flag = 0;
uint16_t	*g_f_p_a;

void	put_figure_in_array(char index, u_int8_t x, u_int8_t y)
{
	g_f_p_a[g_counter] = index + (x << 5) + (y << 9);
	++g_counter;
}

int		se_pos_st(t_f *figure, t_f *m_f, t_f *borders, char *str)
{
	t_f f_c;
	t_s se_st;
	int y;
	int x;

	y = 0;
	se_st.max_x_f = count_for_max_x(figure);
	se_st.max_y_f = count_for_max_y(figure);
	se_st.max_x = g_s - se_st.max_x_f + 1;
	se_st.max_y = g_s - se_st.max_y_f + 1;
	copy_in_struct(&f_c, figure);
	if (str[1])
	{
		while (y < se_st.max_y)
		{
			x = 0;
			while (x < se_st.max_x)
			{
				insert_figure(m_f, &f_c);
				cr_bor(borders, m_f);
				put_figure_in_array(*str, x, y);
				if (generate(str + 1))
					return (1);
				--g_counter;
				log_xor(borders, m_f, f_c);
				cr_bor(borders, m_f);
				++x;
				move_right(&f_c);
			}
			++y;
			move_down(figure);
			copy_in_struct(&f_c, figure);
		}
	}
	return (0);
}

int		se_pos(t_f *figure, t_f *m_f, t_f *borders, char *str)
{
	t_f f_c;
	t_s se_po;
	int y;
	int x;

	y = 0;
	se_po.max_x_f = count_for_max_x(figure);
	se_po.max_y_f = count_for_max_y(figure);
	se_po.max_x = g_s - se_po.max_x_f + 1;
	se_po.max_y = g_s - se_po.max_y_f + 1;
	copy_in_struct(&f_c, figure);
	if (str[1])
	{
		while (y < se_po.max_y)
		{
			x = 0;
			while (x < se_po.max_x)
			{
				if (c_c(&f_c, borders) && !c_c(&f_c, m_f))
				{
					insert_figure(m_f, &f_c);
					cr_bor(borders, m_f);
					put_figure_in_array(*str, x, y);
					if (generate(str + 1))
						return (1);
					--g_counter;
					log_xor(borders, m_f, f_c);
					cr_bor(borders, m_f);
				}
				++x;
				move_right(&f_c);
			}
			++y;
			move_down(figure);
			copy_in_struct(&f_c, figure);
		}
	}
	return (0);
}

int		s_p_e(t_f *figure, t_f *m_f, t_f *borders, char *str)
{
	t_f		f_c;
	t_s		e;
	t_s_f	s;
	int		y;
	int		x;

	y = 0;
	s.m_x_f = count_for_max_x(figure);
	s.m_y_f = count_for_max_y(figure);
	s.m_x_b = count_for_max_x(borders);
	s.m_y_b = count_for_max_y(borders);
	e.max_x = ((s.m_x_b + s.m_x_f - 1) <= g_s) ? s.m_x_b : (g_s - s.m_x_f + 1);
	e.max_y = ((s.m_y_b + s.m_y_f - 1) <= g_s) ? s.m_y_b : (g_s - s.m_y_f + 1);
	copy_in_struct(&f_c, figure);
	while (y < e.max_y)
	{
		x = 0;
		while (x < e.max_x)
		{
			if (c_c(&f_c, borders) && !c_c(&f_c, m_f))
			{
				insert_figure(m_f, &f_c);
				cr_bor(borders, m_f);
				put_figure_in_array(*str, x, y);
				copy_in_struct(&g_o_v, m_f);
				log_xor(borders, m_f, f_c);
				cr_bor(borders, m_f);
				return (1);
			}
			++x;
			move_right(&f_c);
		}
		++y;
		move_down(figure);
		copy_in_struct(&f_c, figure);
	}
	return (0);
}

int		generate_start(char *str, int quantity)
{
	t_f			fun_fig;
	t_gen_st	st;
	char		*p;

	st.temp_inital = creat_temp(st.temp_inital, str, quantity);
	st.check_mask = 0;
	st.arg = 0;
	g_counter = 0;
	g_f_p_a = malloc(sizeof(uint16_t) * (quantity + 1));
	g_f_p_a[quantity] = '\0';
	g_s = sqrt(MIN_SQR_SIZE * quantity);
	char		d2garray[g_s][g_s];

	if (g_flag == 1)
		g_s += 1;
	if (str[1])
	{
		p = str;
		while (*p && st.arg != 1)
		{
			if ((st.check_mask & (1 << (*p))) == 0)
			{
				st.check_mask |= 1 << (*p);
				gen_start_swap(p, str);
				set_figure(&fun_fig, create_tetro(*str));
				st.arg = se_pos_st(&fun_fig, &g_m_f, &g_b_f, str);
				gen_start_swap(p, str);
			}
			++p;
		}
		if (st.arg == 1)
		{
			{
				check_array(st.temp_inital, g_f_p_a, quantity);
				fill_bigarray(g_s, d2garray);
				fill_f_l(g_s, g_f_p_a, d2garray);
				print_bigarray(g_s, d2garray);
				free(g_f_p_a);
				free(st.temp_inital);
				return (1);
			}
		}
		else
		{
			g_flag = 1;
			free(g_f_p_a);
			free(st.temp_inital);
			generate_start(str, quantity);
		}
	}
	return (0);
}

int		generate(char *str)
{
	t_f		fun_fig;
	t_gen	gen;

	gen.check_mask = 0;
	if (str[1])
	{
		gen.p = str;
		while (*gen.p)
		{
			if ((gen.check_mask & (1 << (*gen.p))) == 0)
			{
				gen.check_mask |= 1 << (*gen.p);
				gen_swap(&gen, str);
				set_figure(&fun_fig, create_tetro(*str));
				if (se_pos(&fun_fig, &g_m_f, &g_b_f, str))
					return (1);
				gen_swap(&gen, str);
			}
			++gen.p;
		}
	}
	else
	{
		set_figure(&fun_fig, create_tetro(*str));
		if (s_p_e(&fun_fig, &g_m_f, &g_b_f, str))
			return (1);
	}
	return (0);
}
