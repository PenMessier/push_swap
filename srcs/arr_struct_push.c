/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:05:01 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 10:51:42 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

void			push_back_ar(t_ar **ar, t_ar *new)
{
	t_ar *last;

	last = *ar;
	if (*ar == NULL)
	{
		*ar = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

void			push_front_ar(t_ar **ar, t_ar *new)
{
	if (*ar == NULL)
		*ar = new;
	else
	{
		new->next = *ar;
		*ar = new;
	}
}

t_ar			*new_to_ar(t_ar **ar, int n)
{
	t_ar *new;

	if ((new = create_new(n)) == NULL)
		return (NULL);
	push_back_ar(ar, new);
	return (*ar);
}
