/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_step_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:30 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:43:44 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		first_divide_stack_v_2(t_stack *a, t_stack *b, int len,
												t_char_vector *commands)
{
	int sep;
	int return_elem;
	int	ans;

	return_elem = 0;
	sep = find_sep(a, len);
	while (len > 0)
	{
		if (a->data[0] < sep)
		{
			add_command(a, b, commands, "pb");
			add_command(a, b, commands, "rra");
		}
		else
		{
			return_elem++;
			add_command(a, b, commands, "rra");
		}
		len--;
	}
	ans = return_elem;
	return (ans);
}

int		sort_short_part_up_2(t_stack *a, t_stack *b, t_char_vector *commands)
{
	if (a->data[1] < a->data[0] && a->data[1] < a->data[2])
	{
		add_commands(a, b, commands, "ra;pb;rra");
		sort_short_part_up(a, b, 2, commands);
		add_command(a, b, commands, "pa");
		return (0);
	}
	if (a->data[0] < a->data[1] && a->data[0] < a->data[2])
	{
		add_command(a, b, commands, "pb");
		add_command(a, b, commands, "sa");
		add_command(a, b, commands, "pa");
		return (0);
	}
	return (0);
}

int		sort_short_part_up(t_stack *a, t_stack *b, int len,
											t_char_vector *commands)
{
	if (len < 2)
		return (0);
	if (len == 2)
	{
		if (a->data[0] > a->data[1])
			add_command(a, b, commands, "sa");
		return (0);
	}
	if (len == 3)
	{
		if (a->data[0] < a->data[1] && a->data[1] < a->data[2])
			return (0);
		if (a->data[2] < a->data[1] && a->data[2] < a->data[0])
		{
			if (a->data[0] > a->data[1] && a->data[0] > a->data[1])
				add_command(a, b, commands, "sa");
			add_commands(a, b, commands, "pb;sa;pa;sa");
			return (0);
		}
		sort_short_part_up_2(a, b, commands);
	}
	return (0);
}

int		sort_short_part_down_2(t_stack *a, t_stack *b, t_char_vector *commands)
{
	if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
	{
		add_commands(a, b, commands, "ra;pb;rra");
		sort_short_part_down(a, b, 2, commands);
		add_command(a, b, commands, "pa");
		return (0);
	}
	if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
	{
		add_command(a, b, commands, "pb");
		add_command(a, b, commands, "sa");
		add_command(a, b, commands, "pa");
		return (0);
	}
	return (0);
}

int		sort_short_part_down(t_stack *a, t_stack *b, int len,
													t_char_vector *commands)
{
	if (len < 2)
		return (0);
	if (len == 2)
	{
		if (a->data[0] < a->data[1])
			add_command(a, b, commands, "sa");
		return (0);
	}
	if (len == 3)
	{
		if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
			return (0);
		if (a->data[2] > a->data[1] && a->data[2] > a->data[0])
		{
			if (a->data[0] < a->data[1] && a->data[0] < a->data[1])
				add_command(a, b, commands, "sa");
			add_commands(a, b, commands, "pb;sa;pa;sa");
			return (0);
		}
		sort_short_part_down_2(a, b, commands);
	}
	return (0);
}
