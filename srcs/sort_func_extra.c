/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:27:16 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 11:02:27 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

void		index_ar(t_ar *ar)
{
	int i;

	i = 0;
	while (ar)
	{
		ar->i = i;
		i++;
		ar = ar->next;
	}
}

t_ar		*get_max(t_ar *ar)
{
	t_ar	*tmp;
	t_ar *first;
	t_ar *max;
	int		size;
	int		i;

	first = ar;
	max = ar;
	size = get_arr_size(ar);
	while (ar)
	{
		tmp = ar;
		i = 0;
		while (i < size)
		{
			if ((tmp->next == NULL ? first : tmp->next)->val < tmp->val)
				break ;
			ar->sort++;
			i++;
			tmp = tmp->next == NULL ? first : tmp->next;
		}
		max = ar->sort >= max->sort ? ar : max;
		ar = ar->next;
	}
	return (max);
}

int			est_act_count(int size, int i)
{
	if (i <= size / 2)
		return (i);
	else
		return (-1 * (size - i));
}

int			get_right_place(t_ar *ar, int val)
{
	t_ar *new;
	int		diff;

	new = NULL;
	diff = 0;
	while (ar)
	{
		if ((diff == 0) || (diff < 0 && ar->val - val < 0 &&
			ar->val - val > diff) ||
			(diff > 0 && ar->val - val < diff))
		{
			diff = ar->val - val;
			new = ar;
		}
		if (ar->next == NULL)
			break ;
		ar = ar->next;
	}
	if (new == ar && diff < 0)
		return (-1);
	return (diff < 0 ? new->i + 1 : new->i);
}

int			act_count_to_pa(int a, int b, int b_pos)
{
	if (a > 0 && b > 0 && b_pos != -1)
		return (a > b ? a : b);
	if (a < 0 && b < 0 && b_pos != -1)
		return ((ft_abs(a) > ft_abs(b)) ? ft_abs(a) : ft_abs(b));
	else
		return (ft_abs(a) + ft_abs(b));
}
