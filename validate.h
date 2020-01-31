/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:11:05 by ncharlen          #+#    #+#             */
/*   Updated: 2020/01/28 13:12:40 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_VALIDATE_H
# define FILLIT_VALIDATE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

int get_figure_numbers(char *a);
int get_figures(char *a, int fd);
int check_figure(char *buf);
int c_buf_f(int symbols, int new_string, int i, char *buf);
int c_buf_f_2 (int symbols, int i);

#endif
