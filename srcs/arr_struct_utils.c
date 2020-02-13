/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:30:15 by frenna            #+#    #+#             */
/*   Updated: 2020/02/13 16:12:59 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

t_ar		*create_new(int n)
{
	t_ar	*new;

	if ((new = (t_ar*)malloc(sizeof(t_ar))) == NULL)
		return (NULL);
	new->val = n;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

int			get_arr_size(t_ar *ar)
{
	int		i;

	i = 0;
	while (ar)
	{
		ar = ar->next;
		i++;
	}
	return (i);
}

static void	create_arr_a(int ac, char **av, t_arr *arr)
{
	int		n;
	int		i;
	char	*tmp;

	i = (ac == 2) ? 0 : 1;
	av = (ac == 2) ? ft_strsplit(av[1], ' ') : av;
	while ((ac == 2) ? (int)av[i] : i < ac)
	{
		if (!ft_strcmp(av[i], "-v"))
			arr->flag = 1;
		else
		{
			n = ft_atoi(av[i]);
			if (ft_strcmp((tmp = ft_itoa(n)), av[i]) || find_duplic(arr->a, n)
			|| !new_to_ar(&arr->a, n))
			{
				free(tmp);
				put_error(&arr, ft_free_array((ac == 2) ? av : NULL, 1));
			}
			free(tmp);
		}
		i++;
	}
	ft_free_array((ac == 2) ? av : NULL, 1);
}

t_arr		*create_arr(int ac, char **av)
{
	t_arr	*arr;

	if (!(arr = (t_arr*)malloc(sizeof(t_arr))))
		put_error(&arr, 1);
	arr->a = NULL;
	arr->b = NULL;
	arr->flag = 0;
	arr->act_count = 0;
	arr->print = 0;
	create_arr_a(ac, av, arr);
	return (arr);
}
