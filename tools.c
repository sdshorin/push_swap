/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:51:09 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:51:10 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_commands(t_stack *a, t_stack *b, t_char_vector *c_vec,
													char *commands)
{
	char	**command_array;
	char	**array_to_delete;

	command_array = ft_strsplit(commands, ';');
	array_to_delete = command_array;
	while (*command_array)
	{
		add_command(a, b, c_vec, *command_array);
		command_array++;
	}
	delete_str_array(array_to_delete);
	return (0);
}

int		find_sep(t_stack *a, int len)
{
	int		*data;
	int		sep;

	data = (int*)malloc(len * sizeof(int));
	if (!data)
		return (a->data[len / 2]);
	ft_memcpy(data, a->data, len * sizeof(int));
	ft_quick_sort(data, 0, len - 1);
	sep = data[len / 2];
	free(data);
	return (sep);
}

int		is_stack_sorted_up(t_stack *a, int size)
{
	if (size < 2)
		return (0);
	while (size - 2 >= 0)
	{
		if (a->data[size - 1] < a->data[size - 2])
			return (0);
		size--;
	}
	return (1);
}

int		is_stack_sorted_down(t_stack *a, int size)
{
	if (size < 2)
		return (0);
	while (size - 2 >= 0)
	{
		if (a->data[size - 1] > a->data[size - 2])
			return (0);
		size--;
	}
	return (1);
}
