
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
			set_gen_p0(q, str, &g_gg);
			++q->p;
		}
		if (set_gen_arg(q, d2garray, quantity,str))
			return (1);
	}
	return (0);
}