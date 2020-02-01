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

int	gen_else(t_gg *g_gg, char *str, t_gen *gen_p)
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

/*int	se_pos_st_else(t_s *se_st_p, t_f *borders, char *str)
{
	t_xy	se_xy;

	se_xy.y = 0;
	while (se_xy.y < se_st_p->max_y)
	{
		se_xy.x = 0;
		while (se_xy.x < se_st_p->max_x)
		{
			insert_figure(m_f, &f_c);
			cr_bor(borders, m_f);
			put_figure_in_array(*str, se_xy.x, se_xy.y);
			if (generate(str + 1))
				return (1);
			--g_counter;
			log_xor(borders, m_f, f_c);
			cr_bor(borders, m_f);
			++se_xy.x;
			move_right(&f_c);
		}
		++se_xy.y;
		move_down(figure);
		copy_in_struct(&f_c, figure);
	}
}
*/