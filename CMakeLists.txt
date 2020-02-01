cmake_minimum_required(VERSION 3.15)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit main.c field.h field.c figure.c figure.h main_algorithm.c main_algorithm.h fill_print_final_result.c fill_print_final_result.h validate.c validate.h useful_f_p1.c useful_f_p1.h move_figure.c move_figure.h f_f_m_a.c f_f_m_a.h f_f_m_a_p2.c f_f_m_a_p2.h logical.c logical.h f_f_m_a_p3.c f_f_m_a_p3.h f_f_m_a_p4.c f_f_m_a_p4.h)