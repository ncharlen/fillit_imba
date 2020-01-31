/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_f_p1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:11:13 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 15:11:15 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_USEFUL_F_P1_H
# define FILLIT_USEFUL_F_P1_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "field.h"

uint16_t	*create_copy_a(uint16_t *temp, int quantity, uint16_t *for_print);
char		*create_buf(char *buf, int buf_size);
int			free_buf(char *buf);
void		m_up_right(t_f *p);
void		l_c(t_f *p, t_f *p2, t_f *p3);

#endif
