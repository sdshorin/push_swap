#include "push_swap.h"


int		find_sep(t_stack *a, int len)
{
	int 	*data;

	data = (int*)malloc(len);
	if (!data)
		return (a->data[len / 2]);
	ft_memcpy(data, a->data, len * sizeof(int));
	// ft_quick_sort(data, len); 
	return (data[len / 2]);
}


int		divide_stack(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int sep;
	int return_elem;

	return_elem = 0;
	sep = find_sep(a, len);
	while (len > 0)
	{
		if (a->data[0] < sep)
			add_command(a, b, commands, "pb\n");
		else
		{
			add_command(a, b, commands, "ra\n");
			return_elem++;
		}
		len--;
	}
	while (return_elem--)
		add_command(a, b, commands, "rra\n");
	return (0);
}






int		sort_step_up(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int size_a;

	if (len < 5)
		return (sort_short_part_up(a, b, len, commands));
	size_a = divide_stack(a, b ,len, commands);
	sort_step_up(a, b, size_a, commands);
	sort_step_down(b, a, len - size_a, commands);
	return_stack(a, b, size_a, commands);
	return (0);
}



int				sort_step_down(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	
}





int				return_stack(t_stack *a, t_stack *b, int size_a, t_char_vector *commands);


