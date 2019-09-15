

#include "push_swap.h"











int		start_sort_v_1(t_stack *a, t_stack *b, t_char_vector *commands)
{
	return sort_step_up(a, b, a->size, commands);
}

int		start_sort_v_2(t_stack *a, t_stack *b, t_char_vector *commands)
{
	int size_a;
	int len;

	len = a->size;
	if (len < 5)
		return (sort_short_part_v_2(a, b, len, commands));
	size_a = first_divide_stack_v_2(a, b ,len, commands);
	sort_step_up(a, b, size_a, commands);
	sort_step_down(b, a, len - size_a, commands);
	return_stack(a, b, size_a, commands);
	return (0);
}


int main(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	t_stack			a_old;
	t_char_vector	commands;
	t_char_vector	commands_v2;

	argv++;
	if (argc-- < 2)
		return (0);
	init_c_vector(&commands);
	init_c_vector(&commands_v2);
	init_stacks(argv, argc, &a, &b, 0);
	copy_stack(&a, &a_old);
	start_sort_v_1(&a, &b, commands);
	set_empty_stack(&b);
	start_sort_v_2(&a_old, &b, commands_v2);
	if (commands.size < commands_v2.size)
		print_ans(&commands);
	else
		print_ans(&commands_v2);
	free_stacks(&a, &b);
	free(a_old.data);
	free_c_vector(&commands_v2);
	free_c_vector(&commands);
}
