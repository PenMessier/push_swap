/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:51:24 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 11:41:31 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

void			print_ar(t_arr *arr)
{
	t_ar *a;
	t_ar *b;

	a = arr->a;
	b = arr->b;
	while (a || b)
	{
		if (a)
			ft_putnbr(a->val);
		else
			write(1, "-", 1);
		write(1, " | ", 3);
		if (b)
			ft_putnbr(b->val);
		else
			write(1, "-", 1);
		write(1, "\n", 1);
		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
	}
	write(1, "\n", 1);
}

static void		act_print(char *act)
{
	ft_putstr(act);
	write(1, "\n", 1);
}

static int		act_apply(char *act, t_arr *arr)
{
	int	r;

	r = 0;
	if (!ft_strcmp(act, "sa") || !ft_strcmp(act, "ss"))
		r = act_swap(&arr->a);
	if (!ft_strcmp(act, "sb") || !ft_strcmp(act, "ss"))
		r = act_swap(&arr->b);
	if (!ft_strcmp(act, "pa"))
		r = act_push(&arr->b, &arr->a);
	if (!ft_strcmp(act, "pb"))
		r = act_push(&arr->a, &arr->b);
	if (!ft_strcmp(act, "ra") || !ft_strcmp(act, "rr"))
		r = act_rot(&arr->a);
	if (!ft_strcmp(act, "rb") || !ft_strcmp(act, "rr"))
		r = act_rot(&arr->b);
	if (!ft_strcmp(act, "rra") || !ft_strcmp(act, "rrr"))
		r = act_revr(&arr->a);
	if (!ft_strcmp(act, "rrb") || !ft_strcmp(act, "rrr"))
		r = act_revr(&arr->b);
	return (r == 0 ? 0 : 1);
}

void			make_act(char *act, int count, t_arr *arr)
{
	int	i;

	i = (count < 0) ? -count : count;
	while (i)
	{
		if (act_apply(act, arr))
		{
			if (arr->flag == 1)
				print_ar(arr);
			if (arr->print == 1)
				act_print(act);
			arr->act_count++;
		}
		else
			put_error(&arr, 0);
		i--;
	}
}
