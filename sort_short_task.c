/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_task.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:49:18 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/07 21:49:27 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_short_task(t_stack *a, t_stack *b, int len,
													t_char_vector *commands)
{
	if (len < 3)
		return (sort_short_part_up(a, b, len, commands));
	if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
	{
		add_command(a, b, commands, "ra");
		sort_short_part_up(a, b, 2, commands);
		return (0);
	}
	if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
	{
		add_command(a, b, commands, "rra");
		sort_short_part_up(a, b, 2, commands);
		return (0);
	}
	sort_short_part_up(a, b, 2, commands);
	return (0);
}
