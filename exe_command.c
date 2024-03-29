/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:05 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:43:10 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exe_rra(t_stack *a)
{
	int temp;

	if (a->size <= 0)
		return (1);
	temp = a->data[a->size - 1];
	move_stack(a, "add");
	a->data[0] = temp;
	return (0);
}

int		exe_rrr(t_stack *a, t_stack *b)
{
	exe_rra(a);
	exe_rra(b);
	return (0);
}

int		put_stack_element(t_stack *a, int i)
{
	if (i >= a->size)
		ft_putchar(' ');
	else
		ft_putnbr(a->data[i]);
	return (0);
}

int		exe_command_v(char *command, t_stack *a, t_stack *b, int len)
{
	int i;

	i = 0;
	write(1, "----------------\nExec ", 22);
	write(1, command, ft_strlen(command));
	write(1, "\n", 1);
	while (i < len)
	{
		put_stack_element(a, i);
		write(1, "\t", 2);
		put_stack_element(b, i++);
		write(1, "\n", 1);
	}
	write(1, "_\t_\na\tb\n", 9);
	ft_putnbr(a->size);
	write(1, "\t", 1);
	ft_putnbr(b->size);
	write(1, "\n", 1);
	return (0);
}

int		exe_command(char *command, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(command, "sa"))
		return (exe_s(a));
	else if (!ft_strcmp(command, "sb"))
		return (exe_s(b));
	else if (!ft_strcmp(command, "ss"))
		return (exe_ss(a, b));
	else if (!ft_strcmp(command, "pa"))
		return (exe_pa(a, b));
	else if (!ft_strcmp(command, "pb"))
		return (exe_pa(b, a));
	else if (!ft_strcmp(command, "ra"))
		return (exe_ra(a));
	else if (!ft_strcmp(command, "rb"))
		return (exe_ra(b));
	else if (!ft_strcmp(command, "rr"))
		return (exe_rr(a, b));
	else if (!ft_strcmp(command, "rra"))
		return (exe_rra(a));
	else if (!ft_strcmp(command, "rrb"))
		return (exe_rra(b));
	else if (!ft_strcmp(command, "rrr"))
		return (exe_rrr(a, b));
	else
		return (error(a, b));
}
