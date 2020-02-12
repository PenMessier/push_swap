/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:04:30 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 11:08:32 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

void	pre_sort(t_arr *arr)
{
	int act;

	index_ar(arr->a);
	arr->max_sort = get_max(arr->a);
	arr->si_a = get_arr_size(arr->a);
	if (arr->si_a - arr->max_sort->i - arr->max_sort->sort > 0)
		act = arr->max_sort->i + arr->max_sort->sort;
	else
		act = ft_abs(arr->si_a - arr->max_sort->i - arr->max_sort->sort);
	act = est_act_count(arr->si_a, act);
	make_act(act > 0 ? "ra" : "rra", act, arr);
}

void	pb(t_arr *arr)
{
	t_ar *a;

	a = arr->a;
	while (a && a->i != arr->max_sort->i)
	{
		a = a->next;
		make_act("pb", 1, arr);
	}
}

void	sort_push_a(t_arr *arr)
{
	arr->tmp_b = ft_abs(arr->opt_b);
	arr->tmp_a = ft_abs(arr->opt_a);
	while (((arr->opt_b > 0 && arr->opt_a > 0) || (arr->opt_b < 0 &&
		arr->opt_a < 0)) && arr->tmp_b && arr->tmp_a && arr->opt_pl != -1)
	{
		if (arr->opt_b > 0)
			make_act("rr", 1, arr);
		else
			make_act("rrr", 1, arr);
		arr->tmp_b--;
		arr->tmp_a--;
	}
	make_act(arr->opt_b > 0 ? "rb" : "rrb", arr->tmp_b, arr);
	if (arr->opt_pl != -1)
		make_act(arr->opt_a > 0 ? "ra" : "rra", arr->tmp_a, arr);
	make_act("pa", 1, arr);
	if (arr->opt_pl == -1)
		make_act("ra", 1, arr);
}

void	pa(t_arr *arr)
{
	t_ar *tmp_b;
	int		acts_n;
	int		acts;

	while (arr->b)
	{
		tmp_b = arr->b;
		index_ar(arr->a);
		index_ar(arr->b);
		arr->si_a = get_arr_size(arr->a);
		arr->si_b = get_arr_size(arr->b);
		acts_n = set_act_a_b(arr, tmp_b);
		copy_act_a_b(arr);
		while (tmp_b)
		{
			acts = set_act_a_b(arr, tmp_b);
			if (acts_n > acts)
			{
				acts_n = acts;
				copy_act_a_b(arr);
			}
			tmp_b = tmp_b->next;
		}
		sort_push_a(arr);
	}
}

void	up_min(t_arr *arr)
{
	t_ar	*tmp_a;
	t_ar	*min;
	int		i_count;

	tmp_a = arr->a;
	min = tmp_a;
	while (tmp_a)
	{
		min = (tmp_a->val < min->val) ? tmp_a : min;
		tmp_a = tmp_a->next;
	}
	arr->si_a = get_arr_size(arr->a);
	index_ar(arr->a);
	i_count = est_act_count(arr->si_a, min->i);
	if (i_count > 0)
		make_act("ra", i_count, arr);
	else
		make_act("rra", i_count, arr);
}
