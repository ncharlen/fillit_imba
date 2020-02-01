
#include "main_a_sup.h"
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

extern t_gg		g_gg;
extern int		g_s;
extern int		g_counter;
extern uint16_t	*g_f_p_a;
int			g_flag = 0;

int		generate_start(char *str, int quantity)
{
	t_ms		ms;
	t_ms		*q;
	char		d2garray[(g_s = sqrt(M_S * quantity))][(g_s = sqrt(M_S * quantity))];

	q = &ms;
	set_gen_st(q, str, quantity);
	if (g_flag == 1)
		g_s += 1;
	if (str[1])
	{
		while (*q->p && q->st->arg != 1)
		{
			if ((q->st->check_mask & (1 << (*q->p))) == 0)
			{
				q->st->check_mask |= 1 << (*q->p);
				gen_start_swap(q->p, str);
				set_figure(&q->fun_fig, create_tetro(*str));
				q->st->arg = se_pos_st(&q->fun_fig, &g_gg, str);
				gen_start_swap(q->p, str);
			}
			++q->p;
		}
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
	}
	return (0);
}