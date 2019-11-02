/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:49 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:43:52 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *a)
{
	int pos;

	pos = 0;
	while (pos + 1 < a->size)
	{
		if (a->data[pos] > a->data[pos + 1])
			return (0);
		pos++;
	}
	return (1);
}

int		is_empty(t_stack *b)
{
	return (!b->size);
}

int		free_stacks(t_stack *a, t_stack *b)
{
	free(a->data);
	free(b->data);
	return (1);
}
