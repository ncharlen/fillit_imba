/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:14:09 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/27 12:14:40 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include "figure.h"
#include "main_algorithm.h"
#include "validate.h"
#define MAX_FIG 26
//argv[1]
int	main(int argc, char **argv)
{
	char	*a;
	int		fd;
	int		n;

/*	if (argc != 2)
	{
		printf("usage: fillit input_file\n");
		return (1);
	}*/
	fd = open("/Users/dark/Documents/code/fillit_imba/example_valid", O_RDONLY);
	a = malloc(sizeof(char) * (MAX_FIG + 1));
	ft_memset(a, '\0', 27);
	if (get_figures(a, fd) == -1)
	{
		printf("error\n");
		return (1);
	}
	n = get_figure_numbers(a);
	generate_start(a, n);
	free(a);
	close(fd);
	return (0);
}
