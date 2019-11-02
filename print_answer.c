/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:19 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:43:22 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		print_step(int com)
{
	if (com == SA)
		write(1, "sa\n", 3);
	else if (com == SB)
		write(1, "sb\n", 3);
	else if (com == SS)
		write(1, "ss\n", 3);
	else if (com == PA)
		write(1, "pa\n", 3);
	else if (com == PB)
		write(1, "pb\n", 3);
	else if (com == RA)
		write(1, "ra\n", 3);
	else if (com == RB)
		write(1, "rb\n", 3);
	else if (com == RR)
		write(1, "rr\n", 3);
	else if (com == RRA)
		write(1, "rra\n", 4);
	else if (com == RRB)
		write(1, "rrb\n", 4);
	else if (com == RRR)
		write(1, "rrr\n", 4);
	return (0);
}

int		print_ans(t_char_vector *ans)
{
	int i;

	i = 0;
	while (i < (int)ans->size)
	{
		print_step(ans->data[i]);
		i++;
	}
	return (0);
}
