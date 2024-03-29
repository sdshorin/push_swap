/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:24 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:43:26 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		start_sort_v_1(t_stack *a, t_stack *b, t_char_vector *commands)
{
	int size_a;
	int len;

	if (is_stack_sorted_up(a, a->size))
		return (0);
	len = a->size;
	if (len < 4)
		return (sort_short_task(a, b, len, commands));
	a->first_divide = 1;
	size_a = divide_stack(a, b, len, commands);
	a->first_divide = 0;
	sort_step_up(a, b, size_a, commands);
	sort_step_down(b, a, len - size_a, commands);
	return_stack(a, b, len - size_a, commands);
	return (0);
}

int		start_sort_v_2(t_stack *a, t_stack *b, t_char_vector *commands)
{
	int size_a;
	int len;

	if (is_stack_sorted_up(a, a->size))
		return (0);
	len = a->size;
	if (len < 4)
		return (sort_short_task(a, b, len, commands));
	size_a = first_divide_stack_v_2(a, b, len, commands);
	sort_step_up(a, b, size_a, commands);
	sort_step_down(b, a, len - size_a, commands);
	return_stack(a, b, len - size_a, commands);
	return (0);
}

int		find_best_sort(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	t_stack			a_old;
	t_char_vector	commands;
	t_char_vector	commands_v2;

	init_c_vector(&commands);
	init_c_vector(&commands_v2);
	init_stacks(argv, argc, &a, &b);
	copy_stack(&a, &a_old);
	start_sort_v_1(&a, &b, &commands);
	set_empty_stack(&b);
	start_sort_v_2(&a_old, &b, &commands_v2);
	if (commands.size < commands_v2.size)
		print_ans(&commands);
	else
		print_ans(&commands_v2);
	free_stacks(&a, &b);
	free(a_old.data);
	free_c_vector(&commands_v2);
	free_c_vector(&commands);
	return (0);
}

int		main(int argc, char **argv)
{
	int	need_free;

	need_free = 0;
	argv++;
	if (argc-- < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 1)
	{
		argc = words_counter(*argv, ' ');
		argv = ft_strsplit(*argv, ' ');
		need_free = 1;
	}
	find_best_sort(argc, argv);
	if (need_free)
		delete_str_array(argv);
}
