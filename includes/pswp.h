/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:31:37 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 12:16:24 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWP_H
# define PSWP_H

# include "../libft/libft.h"

typedef struct		s_ar
{
	int				val;
	int				i;
	int				sort;
	struct s_ar	*next;
}					t_ar;

typedef struct		s_arr
{
	t_ar			*a;
	t_ar			*b;
	t_ar			*max_sort;
	int				si_a;
	int				si_b;
	int				opt_a;
	int				opt_b;
	int				opt_pl;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				print;
	int				act_count;
	int				flag;
}					t_arr;

/*
** Actions operating functions
*/

int					act_swap(t_ar **ar);
int					act_rot(t_ar **ar);
int					act_revr(t_ar **ar);
int					act_push(t_ar **from, t_ar **to);

/*
** Apply actions and output functions
*/

void				make_act(char *act, int count, t_arr *arr);
int					set_act_a_b(t_arr *arr, t_ar *tmp_b);
void				copy_act_a_b(t_arr *arr);
void				print_ar(t_arr *arr);

/*
** Sorting functions
*/

void				pre_sort(t_arr *arr);
void				pb(t_arr *arr);
void				sort_push_a(t_arr *arr);
void				pa(t_arr *arr);
void				up_min(t_arr *arr);

/*
** Extra sorting functions
*/

void				index_ar(t_ar *ar);
t_ar				*get_max(t_ar *ar);
int					est_act_count(int size, int i);
int					get_right_place(t_ar *ar, int val);
int					act_count_to_pa(int a, int b, int b_pos);

/*
** Structure fucntions
*/

t_ar				*pop_front(t_ar **ar);
t_ar				*pop_back(t_ar **ar);
void				push_back_ar(t_ar **ar, t_ar *new);
void				push_front_ar(t_ar **ar, t_ar *new);
t_ar				*new_to_ar(t_ar **ar, int n);
t_ar				*create_new(int n);
int					get_arr_size(t_ar *ar);
t_arr				*create_arr(int ac, char **av);

/*
** Check input functions
*/

int					find_duplic(t_ar *ar, int n);
int					ar_is_sorted(t_arr *arr);

/*
** Error and memory management
*/

void				free_arr(t_arr **arr);
void				put_error(t_arr **arr, int r);

#endif
