/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:35:08 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 15:35:10 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_figure.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "fill_print_final_result.h"

#define MASK_MOVE_LEFT 			0x0101010101010101
#define MASK_MOVE_RIGHT 		0x8080808080808080
#define MASK_MOVE_DOWN 			0xFF00000000000000
#define MASK_MOVE_UP 			0x00000000000000FF
#define MASK_MOVE_L 			0x7F7F7F7F7F7F7F7F
#define MASK_MOVE_R 			0xFEFEFEFEFEFEFEFE

void	move_right(t_f *p)
{
	uint64_t mask_for_copy_1;
	uint64_t mask_for_copy_2;
	uint64_t mask_border;

	mask_for_copy_1 = p->sqrt0 & MASK_MOVE_RIGHT;
	mask_for_copy_2 = p->sqrt2 & MASK_MOVE_RIGHT;
	mask_border = MASK_MOVE_R;
	p->sqrt0 = (p->sqrt0 ^ mask_for_copy_1) << 1;
	p->sqrt1 = ((p->sqrt1 << 1) & mask_border) | (mask_for_copy_1 >> 7);
	p->sqrt2 = (p->sqrt2 ^ mask_for_copy_2) << 1;
	p->sqrt3 = ((p->sqrt3 << 1) & mask_border) | (mask_for_copy_2 >> 7);
}

void	move_left(t_f *p)
{
	uint64_t mask_for_copy_1;
	uint64_t mask_for_copy_2;
	uint64_t mask_border;

	mask_for_copy_1 = p->sqrt1 & MASK_MOVE_LEFT;
	mask_for_copy_2 = p->sqrt3 & MASK_MOVE_LEFT;
	mask_border = MASK_MOVE_L;
	p->sqrt1 = (p->sqrt1 ^ mask_for_copy_1) >> 1;
	p->sqrt0 = ((p->sqrt0 >> 1) & mask_border) | (mask_for_copy_1 << 7);
	p->sqrt3 = (p->sqrt3 ^ mask_for_copy_2) >> 1;
	p->sqrt2 = ((p->sqrt2 >> 1) & mask_border) | (mask_for_copy_2 << 7);
}

void	move_up(t_f *p)
{
	uint64_t mask_for_copy_1;
	uint64_t mask_for_copy_2;

	mask_for_copy_1 = p->sqrt2 & MASK_MOVE_UP;
	mask_for_copy_2 = p->sqrt3 & MASK_MOVE_UP;
	p->sqrt2 = (p->sqrt2 ^ mask_for_copy_1) >> 8;
	p->sqrt0 = (p->sqrt0 >> 8) | (mask_for_copy_1 << 56);
	p->sqrt3 = (p->sqrt3 ^ mask_for_copy_2) >> 8;
	p->sqrt1 = (p->sqrt1 >> 8) | (mask_for_copy_2 << 56);
}

void	move_down(t_f *p)
{
	uint64_t mask_for_copy_1;
	uint64_t mask_for_copy_2;

	mask_for_copy_1 = p->sqrt0 & MASK_MOVE_DOWN;
	mask_for_copy_2 = p->sqrt1 & MASK_MOVE_DOWN;
	p->sqrt0 = (p->sqrt0 ^ mask_for_copy_1) << 8;
	p->sqrt2 = (p->sqrt2 << 8) | (mask_for_copy_1 >> 56);
	p->sqrt1 = (p->sqrt1 ^ mask_for_copy_2) << 8;
	p->sqrt3 = (p->sqrt3 << 8) | (mask_for_copy_2 >> 56);
}
