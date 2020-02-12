/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:04:45 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 10:47:11 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

t_ar			*pop_front(t_ar **ar)
{
	t_ar *tmp;

	if (*ar == NULL)
		return (NULL);
	tmp = *ar;
	if ((*ar)->next == NULL)
		*ar = NULL;
	else
		*ar = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_ar			*pop_back(t_ar **ar)
{
	t_ar *pre_last;
	t_ar *tmp;

	pre_last = *ar;
	tmp = *ar;
	if (*ar == NULL)
		return (NULL);
	if ((*ar)->next == NULL)
		*ar = NULL;
	else
	{
		while (pre_last->next && pre_last->next->next)
			pre_last = pre_last->next;
		tmp = pre_last->next;
		pre_last->next = NULL;
	}
	return (tmp);
}
