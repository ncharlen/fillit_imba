/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:11:36 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:11:38 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FIELD_H
# define FILLIT_FIELD_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_fillit_field{
	uint64_t	sqrt0;
	uint64_t	sqrt1;
	uint64_t	sqrt2;
	uint64_t	sqrt3;

}				t_f;

void			cr_bor(t_f *borders_field, t_f *main_field);
int				c_c(t_f *p_one, t_f *p_two);
void			insert_figure(t_f *main_field, t_f *figure);
int8_t			count_for_max_x(t_f *borders_field);
int8_t			count_for_max_y(t_f *borders_field);

#endif
