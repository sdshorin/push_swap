#include "push_swap.h"


int		find_sep(t_stack *a, int len)
{
	int 	*data;
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


int		divide_stack(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int sep;
	int return_elem;
	int	ans;

	return_elem = 0;
	sep = find_sep(a, len);
	// printf ("sep: %d, len: %d\n", sep, len);
	while (len > 0)
	{
		if (a->data[0] < sep)
		{
			add_command(a, b, commands, "pb");
			return_elem++;
		}
		else
			add_command(a, b, commands, "ra");
		len--;
	}
	ans = return_elem;
	while (return_elem--)
		add_command(a, b, commands, "rra");
	// printf("---------finish divide------------\n");
	return (ans);
}


int		divide_stack_down(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int sep;
	int return_elem;
	int	ans;

	return_elem = 0;
	sep = find_sep(a, len);
	// printf ("sep: %d, len: %d\n", sep, len);
	while (len > 0)
	{
		if (a->data[0] >= sep)
		{
			add_command(a, b, commands, "pb");
			return_elem++;
		}
		else
			add_command(a, b, commands, "ra");
		len--;
	}
	ans = return_elem;
	while (return_elem--)
		add_command(a, b, commands, "rra");
	// printf("---------finish divide------------\n");
	return (ans);
}

int		sort_step_up(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int size_a;

	// if (is_stack_sorted_up(a, len))
	// 	return (0);
	if (len < 4)
		return (sort_short_part_up(a, b, len, commands));
	size_a = divide_stack(a, b ,len, commands);
	sort_step_up(a, b, len - size_a, commands);
	sort_step_down(b, a,  size_a, commands);
	return_stack(a, b, size_a, commands);
	return (0);
}



int				sort_step_down(t_stack *a, t_stack *b, int len, t_char_vector *commands)
{
	int size_a;

	// if (is_stack_sorted_down(a, len))
	// 	return (0);
	if (len < 4)
		return (sort_short_part_down(a, b, len, commands));
	size_a = divide_stack_down(a, b ,len, commands);
	sort_step_down(a, b, len - size_a, commands);
	sort_step_up(b, a, size_a, commands);
	return_stack(a, b, size_a, commands);
	return (0);
}





int				return_stack(t_stack *a, t_stack *b, int size_a, t_char_vector *commands)
{
	// printf("-------start return stack\n");
	while (size_a-- > 0)
		add_command(a, b, commands, "pa");
	// printf("-------finish return stack\n");
	return (0);
}


