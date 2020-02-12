/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:51:04 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 11:20:40 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

int	act_swap(t_ar **ar)
{
	int	tmp;

	if (*ar && (*ar)->next)
	{
		tmp = (*ar)->val;
		(*ar)->val = (*ar)->next->val;
		(*ar)->next->val = tmp;
		return (1);
	}
	return (-1);
}

int	act_rot(t_ar **ar)
{
	if (*ar && (*ar)->next)
	{
		push_back_ar(ar, pop_front(ar));
		return (1);
	}
	return (-1);
}

int	act_revr(t_ar **ar)
{
	if (*ar && (*ar)->next)
	{
		push_front_ar(ar, pop_back(ar));
		return (1);
	}
	return (-1);
}

int	act_push(t_ar **from, t_ar **to)
{
	if (*from)
	{
		push_front_ar(to, pop_front(from));
		return (1);
	}
	return (-1);
}
