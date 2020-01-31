/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:05:20 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/31 15:05:25 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_LOGICAL_H
# define FILLIT_LOGICAL_H
# include "field.h"

void	set_x_max(t_f *p);
void	set_y_max(t_f *p);
void	logical_or(t_f *p_one, t_f *p_two);
void	logical_xor(t_f *p_one, t_f *p_two);
void	copy_in_struct(t_f *p_one, t_f *p_two);

#endif
