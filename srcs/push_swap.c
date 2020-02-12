/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:36:52 by frenna            #+#    #+#             */
/*   Updated: 2020/02/12 10:28:57 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

static void	easy_sort(t_arr *arr)
{
	if (arr->a->val > arr->a->next->val &&
		arr->a->val < arr->a->next->next->val)
		make_act("sa", 1, arr);
	else if (arr->a->val > arr->a->next->next->val)
		make_act("ra", 1, arr);
}

static void	five_sort(t_arr *arr)
{
	if (arr->max_sort->sort < 3)
	{
		make_act("pb", 2, arr);
		easy_sort(arr);
	}
	else
		pb(arr);
	pa(arr);
	up_min(arr);
}

int			main(int ac, char **av)
{
	t_arr *arr;

	arr = create_arr(ac, av);
	if (arr->a == NULL)
	{
		free_arr(&arr);
		return (0);
	}
	arr->print = 1;
	arr->si_a = get_arr_size(arr->a);
	pre_sort(arr);
	if (arr->si_a == 3)
		easy_sort(arr);
	else if (arr->si_a == 5)
		five_sort(arr);
	else
	{		
		pb(arr);
		pa(arr);
		up_min(arr);
	}
	free_arr(&arr);
	return (0);
}
