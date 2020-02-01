/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f_m_a_p3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:46:47 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/31 14:46:48 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_F_F_M_A_P3_H
# define FILLIT_F_F_M_A_P3_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "field.h"
# include "main_algorithm.h"

void	se_pos_m(t_m *p, t_f *figure);
void	se_pos_d(t_m *p, t_f *figure);
void	set_s_p_e(t_m2 *p, int g_s, t_gg *g, t_f *figure);

#endif
