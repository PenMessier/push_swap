/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:30:25 by frenna            #+#    #+#             */
/*   Updated: 2020/02/13 16:16:34 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pswp.h"

int			main(int ac, char **av)
{
	t_arr	*arr;
	char	*act;

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
