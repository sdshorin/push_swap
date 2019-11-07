/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_step_common.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:27 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:43:29 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		divide_stack(t_stack *a, t_stack *b, int len,
													t_char_vector *commands)
{
	int sep;
	int return_elem;
	int	ans;
	// printf("stert divide");
	return_elem = 0;
	sep = find_sep(a, len);
	while (len > 0)
	{
		if (a->data[0] < sep)
		{
			add_command(a, b, commands, "pb");
		}
		else
		{
			add_command(a, b, commands, "ra");
			return_elem++;
		}
		len--;
	}
	if (a->first_divide)
		return (return_elem);
	ans = return_elem;
	while (return_elem--)
		add_command(a, b, commands, "rra");
	// printf("finfish divide");

	return (ans);
}

int		divide_stack_down(t_stack *a, t_stack *b, int len,
													t_char_vector *commands)
{
	int sep;
	int return_elem;
	int	ans;

	// printf("start divide");

	return_elem = 0;
	sep = find_sep(a, len);
	while (len > 0)
	{
		if (a->data[0] >= sep)
		{
			add_command(a, b, commands, "pb");
		}
		else
		{
			add_command(a, b, commands, "ra");
			return_elem++;
		}
		len--;
	}
	ans = return_elem;
	while (return_elem--)
		add_command(a, b, commands, "rra");
	// printf("finish divide");

	return (ans);
}

int		sort_step_up(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int size_a;

	if (is_stack_sorted_up(a, len))
		return (0);
	if (len < 4)
	{
		// printf("short stert");
		sort_short_part_up(a, b, len, commands);
		// printf("short finish");
		return (0);
	}
	size_a = divide_stack(a, b, len, commands);
	sort_step_up(a, b, size_a, commands);
	sort_step_down(b, a, len - size_a, commands);
	return_stack(a, b, len - size_a, commands);
	return (0);
}

int		sort_step_down(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int size_a;

	if (is_stack_sorted_down(a, len))
		return (0);
	if (len < 4)
	{
		// printf("short stert");
		sort_short_part_down(a, b, len, commands);
		// printf("short finish");
		return(0);
	}
	size_a = divide_stack_down(a, b, len, commands);
	sort_step_down(a, b, size_a, commands);
	sort_step_up(b, a, len - size_a, commands);
	return_stack(a, b, len - size_a, commands);
	return (0);
}

int		return_stack(t_stack *a, t_stack *b, int size_a,
													t_char_vector *commands)
{
	// printf("start return");

	while (size_a-- > 0)
		add_command(a, b, commands, "pa");
	// printf("finish return");
	return (0);
}
