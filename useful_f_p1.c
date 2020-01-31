/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_f_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:11:04 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 15:11:15 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_f_p1.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "move_figure.h"

uint16_t	*create_copy_a(uint16_t *temp, int quantity, uint16_t *for_print)
{
	int i;

	i = 0;
	temp = malloc(sizeof(uint16_t) * (quantity + 1));
	temp[quantity] = '\0';
	while (i < quantity)
	{
		temp[i] = for_print[i];
		++i;
	}
	return (temp);
}

char		*create_buf(char *buf, int buf_size)
{
	buf = malloc(sizeof(char) * (buf_size + 1));
	buf[buf_size] = '\0';
	return (buf);
}

int			free_buf(char *buf)
{
	free(buf);
	return (-1);
}

void		m_up_right(t_f *p)
{
	move_up(p);
	move_right(p);
}

void		l_c(t_f *p, t_f *p2, t_f *p3)
{
	logical_or(p, p3);
	copy_in_struct(p3, p2);
}
