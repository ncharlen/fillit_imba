/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:12:25 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:12:27 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_MAIN_ALGORITHM_H
# define FILLIT_MAIN_ALGORITHM_H
# include <math.h>
# define MIN_SQR_SIZE 4

typedef struct	s_search{
	int max_x_f;
	int max_y_f;
	int max_x;
	int max_y;

}				t_s;

typedef struct	s_s_fig{
	int m_x_f;
	int m_y_f;
	int m_x_b;
	int m_y_b;

}				t_s_f;

typedef struct	s_gen{
	char	*p;
	char	temp;
	int8_t	check_mask;

}				t_gen;

typedef struct	s_gen_st{
	char	*temp_inital;
	int8_t	check_mask;
	int		arg;

}				t_gen_st;

int				se_pos_st(t_f *figure, t_f *m_f, t_f *borders, char *str);
int				se_pos(t_f *figure, t_f *m_f, t_f *borders, char *str);
int				s_p_e(t_f *figure, t_f *m_f, t_f *borders, char *str);
int				generate(char *str);
int				generate_start(char *str, int quantity);
void			put_figure_in_array(char index, u_int8_t x, u_int8_t y);

#endif
