/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:49:07 by Elena             #+#    #+#             */
/*   Updated: 2020/02/12 11:52:28 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

int		main(int ac, char **av)
{
	t_arr	*arr;
	char		*act;

	act = NULL;
	arr = create_arr(ac, av);
	arr->print = 0;
	if (arr->a == NULL)
	{
		free_arr(&arr);
		return (0);
	}
	while (get_next_line(0, &act))
	{
		make_act(act, 1, arr);
		if (act)
			free(act);
	}
	if (ar_is_sorted(arr))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_arr(&arr);
	return (0);
}
