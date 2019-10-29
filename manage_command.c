


#include "push_swap.h"


int		add_command_3(t_char_vector *c_vec, char com)
{
	char prev_com;

	prev_com = c_vec->data[c_vec->size - 1];
	if (com == RRA && prev_com == RRB)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec,  RRR));
	}
	if ((com == RRA || com == RRB) && prev_com == RRR)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec,  RRA + (com - RRA + 1) % 2));
	}
		return (c_vector_push_back(c_vec,  com));
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
		return (c_vector_push_back(c_vec,  RR));
	}
	if ((com == RA || com == RB) && prev_com == RR)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec,  RA + (com - RA + 1) % 2));
	}
	return (add_command_3(c_vec, com));
}


int		add_to_command(t_char_vector *c_vec, char com)
{
	char prev_com;

	if (c_vec->size < (size_t)1)
		return (c_vector_push_back(c_vec,  com));
	prev_com = c_vec->data[c_vec->size - 1];
	if (com == SA && prev_com == SA)
		return (c_vector_pop_back(c_vec));
	if (com == SB && prev_com == SB)
		return (c_vector_pop_back(c_vec));
	if (com == SA && prev_com == SB)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec,  SS));
	}
	if ((com == SA || com == SB) && prev_com == SS)
	{
		c_vector_pop_back(c_vec);
		return (c_vector_push_back(c_vec,  (com + 1) % 2));
	}
	if ((com == PA && prev_com == PB) || (com == PB && prev_com == PA))
		return (c_vector_pop_back(c_vec));
	return (add_command_2(c_vec, com));
}


int		add_commands(t_stack *a, t_stack *b, t_char_vector *c_vec, char *commands)
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


void		prepare_command(t_stack *b, char **command)
{
	*command = ft_strdup(*command);
	if (b->type != 'a')
		return ;
	if (ft_findchar(*command, 'a'))
		ft_str_replace(*command, 'a', 'b');
	else
		ft_str_replace(*command, 'b', 'a');
}

void		add_command(t_stack *a, t_stack *b, t_char_vector *c_vec, char *command)
{
	exe_command(command, a, b);
	prepare_command(b, &command);
	if (!ft_strcmp(command, "sa"))
		add_to_command(c_vec, SA);
	else if (!ft_strcmp(command, "sb"))
		add_to_command(c_vec, SB);
	else if (!ft_strcmp(command, "ss"))
		add_to_command(c_vec, SS);
	else if (!ft_strcmp(command, "pa"))
		add_to_command(c_vec, PA);
	else if (!ft_strcmp(command, "pb"))
		add_to_command(c_vec, PB);
	else if (!ft_strcmp(command, "ra"))
		add_to_command(c_vec, RA);
	else if (!ft_strcmp(command, "rb"))
		add_to_command(c_vec, RB);
	else if (!ft_strcmp(command, "rr"))
		add_to_command(c_vec, RR);
	else if (!ft_strcmp(command, "rra"))
		add_to_command(c_vec, RRA);
	else if (!ft_strcmp(command, "rrb"))
		add_to_command(c_vec, RRB);
	else if (!ft_strcmp(command, "rrr"))
		add_to_command(c_vec, RRR);
	free(command);
}