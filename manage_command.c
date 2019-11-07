/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:17 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:43:18 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_command_3(t_char_vector *c_vec, char com)
{
	char prev_com;

	prev_com = c_vec->data[c_vec->size - 1];
	if (com == RRA && prev_com == RRB)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec, RRR));
	}
	if ((com == RRA || com == RRB) && prev_com == RRR)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec, RRA + (com - RRA + 1) % 2));
	}
	return (c_vector_push_back(c_vec, com));
}

int		add_command_2(t_char_vector *c_vec, char com)
{
	char prev_com;

	prev_com = c_vec->data[c_vec->size - 1];
	if ((com == RA && prev_com == RRA) || (prev_com == RA && com == RRA))
		return (c_vector_pop_back(c_vec));
	if ((com == RB && prev_com == RRB) || (prev_com == RB && com == RRB))
		return (c_vector_pop_back(c_vec));
	if (com == RA && prev_com == RB)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec, RR));
	}
	if ((com == RA || com == RB) && prev_com == RR)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec, RA + (com - RA + 1) % 2));
	}
	return (add_command_3(c_vec, com));
}



int reverse_command(char com)
{
	if (com == RA)
		return (RRA);
	if (com == RRA)
		return (RA);
	if (com == RB)
		return (RRB);
	if (com == RRB)
		return (RB);
	write(1, "error\n", 6);
	return(0);
}


int  count_top_elements(t_char_vector *c_vec, char com)
{
	size_t size;
	int counter;

	counter = 0;
	size = 0;

	while (size < c_vec->size)
	{
		if (c_vec->data[c_vec->size - 1 - size] == com)
			counter++;
		else
			return (counter);
		size++;
	}
	return (counter);
}

int check_circle_rotation(t_char_vector *c_vec, char com, int size)
{
	int command_quantity;
	int		temp;

	if (com != RA && com != RB && com != RRA && com != RRB)
	{
		return (0);
	}
	command_quantity = count_top_elements(c_vec, com) + 1;

	if (command_quantity <= size / 2)
		return (0);
	temp = command_quantity - 1;
	while (temp--)
		c_vector_pop_back(c_vec);
	// printf("%d\n", c_vec->data[c_vec->size - 1]);
	temp = size - command_quantity;
	while (temp--)
		c_vector_push_back(c_vec, reverse_command(com));
	return (1);
}


int		add_to_command(t_char_vector *c_vec, char com, int size)
{
	char prev_com;

	if (check_circle_rotation(c_vec, com , size))
		return (1);
	if (com == RA || com == RB || com == RRA || com == RRB)
		if (is_prev_commands_is(c_vec, com, (size_t)(size - 1)))
			return (c_vector_delete_last_elements(c_vec, (size_t)(size - 1)));
	if (c_vec->size < (size_t)1)
		return (c_vector_push_back(c_vec, com));
	prev_com = c_vec->data[c_vec->size - 1];
	if (com == SA && prev_com == SA)
		return (c_vector_pop_back(c_vec));
	if (com == SB && prev_com == SB)
		return (c_vector_pop_back(c_vec));
	if (com == SA && prev_com == SB)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec, SS));
	}
	if ((com == SA || com == SB) && prev_com == SS)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec, (com + 1) % 2));
	}
	if ((com == PA && prev_com == PB) || (com == PB && prev_com == PA))
		return (c_vector_pop_back(c_vec));
	return (add_command_2(c_vec, com));
}

void	prepare_command(t_stack *b, char **command)
{
	*command = ft_strdup(*command);
	if (b->type != 'a')
		return ;
	if (ft_findchar(*command, 'a'))
		ft_str_replace(*command, 'a', 'b');
	else
		ft_str_replace(*command, 'b', 'a');
}

void	add_command(t_stack *a, t_stack *b, t_char_vector *c_vec, char *command)
{
	
	// exe_command_v(command, a, b, ft_max(a->size, b->size));
	exe_command(command, a, b);
	prepare_command(b, &command);
	if (!ft_strcmp(command, "sa"))
		add_to_command(c_vec, SA, a->size);
	else if (!ft_strcmp(command, "sb"))
		add_to_command(c_vec, SB, b->size);
	else if (!ft_strcmp(command, "ss"))
		add_to_command(c_vec, SS, b->size);
	else if (!ft_strcmp(command, "pa"))
		add_to_command(c_vec, PA, b->size);
	else if (!ft_strcmp(command, "pb"))
		add_to_command(c_vec, PB, a->size);
	else if (!ft_strcmp(command, "ra"))
		add_to_command(c_vec, RA, a->size);
	else if (!ft_strcmp(command, "rb"))
		add_to_command(c_vec, RB, b->size);
	else if (!ft_strcmp(command, "rr"))
		add_to_command(c_vec, RR, b->size);
	else if (!ft_strcmp(command, "rra"))
		add_to_command(c_vec, RRA, a->size);
	else if (!ft_strcmp(command, "rrb"))
		add_to_command(c_vec, RRB, b->size);
	else if (!ft_strcmp(command, "rrr"))
		add_to_command(c_vec, RRR, b->size);
	free(command);
}
