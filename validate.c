/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:12:35 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:12:36 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "fill_print_final_result.h"
#include "useful_f_p1.h"
#define BUF_SIZE 21

t_f g_figure;
uint32_t g_t_figure;

int	get_figure_numbers(char *a)
{
	int counter;

	counter = 0;
	while (*a)
	{
		++a;
		++counter;
	}
	return (counter);
}

int	get_figures(char *a, int fd)
{
	int		count;
	char	*buf;
	int		i;

	i = 0;
	buf = create_buf(buf, BUF_SIZE);
	count = read(fd, buf, BUF_SIZE);
	while (count >= 20)
	{
		if ((a[i] = check_figure(buf)) != -1)
		{
			++i;
			count = read(fd, buf, BUF_SIZE);
		}
		else
		{
			free_buf(buf);
		}
	}
	if (count != 0)
	{
		free_buf(buf);
	}
	free(buf);
	return (1);
}

int	check_figure(char *buf)
{
	int			symbols;
	int			new_string;
	int			i;

	symbols = 0;
	new_string = 0;
	i = 0;
	g_t_figure = 0;
	g_t_figure = c_buf_f(symbols, new_string, i, buf);
	if ((g_t_figure = set_and_check_figure(&g_figure, g_t_figure)) == -1)
		return (-1);
	return (g_t_figure);
}

int	c_buf_f(int symbols, int new_string, int i, char *buf)
{
	while (*buf)
	{
		if (*buf == '.')
			++symbols;
		else if (*buf == '#')
			symbols = c_buf_f_2(symbols, i);
		else if (*buf == '\n')
		{
			if (symbols != 4)
				return (-1);
			i += 3;
			symbols = 0;
			if (++new_string == 4)
			{
				++buf;
				break ;
			}
		}
			else return (-1);
		++i;
		++buf;
	}
	if (buf[0] != '\n' || buf[1] != '\0')
		return (-1);
	return (g_t_figure);
}

int	c_buf_f_2(int symbols, int i)
{
	g_t_figure |= (1 << i);
	return (++symbols);
}
