/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:05:48 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 10:37:13 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

int	find_duplic(t_ar *ar, int n)
{
	while (ar)
	{
		if (ar->val == n)
			return (1);
		ar = ar->next;
	}
	return (0);
}

int	ar_is_sorted(t_arr *arr)
{
	t_ar	*a;
	int		last_val;

	if (arr->b != NULL)
		return (0);
	a = arr->a;
	last_val = a->val;
	while (a)
	{
		if (last_val > a->val)
			return (0);
		last_val = a->val;
		a = a->next;
	}
	return (1);
}
