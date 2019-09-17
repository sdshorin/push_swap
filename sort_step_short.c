
#include "push_swap.h"

int		first_divide_stack_v_2(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int sep;
	int return_elem;
	int	ans;


	return_elem = 0;
	sep = find_sep(a, len);
	while (len > 0)
	{
		if (a->data[0] < sep)
			add_command(a, b, commands, "pb\n");
		else
		{
			add_command(a, b, commands, "rra\n");
			return_elem++;
		}
		len--;
	}
	ans = return_elem;
	while (return_elem--)
		add_command(a, b, commands, "ra\n");
	return (ans);

}


int				sort_short_part_up_2(t_stack *a, t_stack *b, t_char_vector *commands)
{
	if (a->data[1] < a->data[0] && a->data[1] < a->data[2])
	{
		add_command(a, b, commands, "pb\n");
		add_command(a, b, commands, "ra\n");
		add_command(a, b, commands, "pa\n");
		sort_short_part_up(a, b, 2, commands);
		add_command(a, b, commands, "rra\n");
		return (0);
	}
	if (a->data[0] < a->data[1] && a->data[0] < a->data[2])
	{
		add_command(a, b, commands, "pb\n");
		add_command(a, b, commands, "sa\n");
		add_command(a, b, commands, "pa\n");
		return (0);
	}
	return (0);
	write (1, "\nERR\n", 5);
}


int				sort_short_part_up(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	if (len < 2)
		return (0);
	if (len == 2)
	{
		if (a->data[0] > a->data[1])
			add_command(a, b, commands, "sa\n");
		return (0);
	}
	if (len == 3)
	{
		if (a->data[0] < a->data[1] && a->data[1] < a->data[2])
			return (0);
		if (a->data[2] < a->data[1] && a->data[2] < a->data[0])
		{
			add_command(a, b, commands, "ra\n");
			add_command(a, b, commands, "ra\n");
			add_command(a, b, commands, "pb\n");
			add_command(a, b, commands, "rra\n");
			add_command(a, b, commands, "rra\n");
			add_command(a, b, commands, "pa\n");
			return (sort_short_part_up(a, b, 2, commands));
		}
		sort_short_part_up_2(a, b, commands);
	}
	return (0);
}


int		sort_short_part_down_2(t_stack *a, t_stack *b, t_char_vector *commands)
{
	if (a->data[1] > a->data[0] && a->data[1] > a->data[2])
	{
		add_command(a, b, commands, "pb\n");
		add_command(a, b, commands, "ra\n");
		add_command(a, b, commands, "pa\n");
		sort_short_part_down(a, b, 2, commands);
		add_command(a, b, commands, "rra\n");
		return (0);
	}
	if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
	{
		add_command(a, b, commands, "pb\n");
		add_command(a, b, commands, "sa\n");
		add_command(a, b, commands, "pa\n");
		return (0);
	}
	return (0);
	write (1, "\nERR\n", 5);
}

int		sort_short_part_down(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	if (len < 2)
		return (0);
	if (len == 2)
	{
		if (a->data[0] < a->data[1])
			add_command(a, b, commands, "sa\n");
		return (0);
	}
	if (len == 3)
	{
		if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
			return (0);
		if (a->data[2] > a->data[1] && a->data[2] > a->data[0])
		{
			add_command(a, b, commands, "ra\n");
			add_command(a, b, commands, "ra\n");
			add_command(a, b, commands, "pb\n");
			add_command(a, b, commands, "rra\n");
			add_command(a, b, commands, "rra\n");
			add_command(a, b, commands, "pa\n");
			return (sort_short_part_down(a, b, 2, commands));
		}
		sort_short_part_down_2(a, b, commands);
	}
	return (0);
}