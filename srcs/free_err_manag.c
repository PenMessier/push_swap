/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:05:34 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 10:30:45 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

static void	free_ar(t_ar **ar)
{
	t_ar	*next;

	while (*ar)
	{
		next = (*ar)->next;
		free(*ar);
		*ar = next;
	}
}

void			free_arr(t_arr **arr)
{
	if (*arr && (*arr)->a)
		free_ar(&(*arr)->a);
	if (*arr && (*arr)->b)
		free_ar(&(*arr)->b);
	if (*arr)
		free(*arr);
}

void		put_error(t_arr **arr, int r)
{
	ft_putstr("Error\n");
	free_arr(arr);
	exit(r);
}

int			set_act_a_b(t_arr *arr, t_ar *tmp_b)
{
	int		n;

	arr->tmp_pl = get_right_place(arr->a, tmp_b->val);
	arr->tmp_b = est_act_count(arr->si_b, tmp_b->i);
	arr->tmp_a = est_act_count(arr->si_a, arr->tmp_pl);
	n = act_count_to_pa(arr->tmp_a, arr->tmp_b, arr->tmp_pl);
	return (n);
}

void		copy_act_a_b(t_arr *arr)
{
	arr->opt_pl = arr->tmp_pl;
	arr->opt_b = arr->tmp_b;
	arr->opt_a = arr->tmp_a;
}
