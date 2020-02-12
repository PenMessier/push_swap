/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:05:15 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 12:12:44 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

t_ar					*create_new(int n)
{
	t_ar *new;

	if ((new = (t_ar*)malloc(sizeof(t_ar))) == NULL)
		return (NULL);
	new->val = n;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

int						get_arr_size(t_ar *ar)
{
	int i;

	i = 0;
	while (ar)
	{
		ar = ar->next;
		i++;
	}
	return (i);
}

static void		create_arr_a(int ac, char **av, t_arr *arr)
{
	int i;
	int n;

	av = (ac == 2) ? ft_strsplit(av[1], ' ') : av;
	i = (ac == 2) ? 0 : 1;
	
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (!ft_strcmp(av[i], "-v"))
			arr->flag = 1;
		else
		{
			n = ft_atoi(av[i]);
			if (ft_strcmp(ft_itoa(n), av[i]) || find_duplic(arr->a, n))
				put_error(&arr, ft_free_array((ac == 2) ? av : NULL, 1));
			if ((!new_to_ar(&arr->a, n)))
				put_error(&arr, ft_free_array((ac == 2) ? av : NULL, 1));
		}
		i++;
	}
	ft_free_array((ac == 2) ? av : NULL, 1);
}

t_arr					*create_arr(int ac, char **av)
{
	t_arr *arr;

	if ((arr = (t_arr*)malloc(sizeof(t_arr))) == NULL)
		put_error(&arr, 1);
	arr->a = NULL;
	arr->b = NULL;
	arr->flag = 0;
	arr->act_count = 0;
	arr->print = 0;
	create_arr_a(ac, av, arr);
	return (arr);
}
