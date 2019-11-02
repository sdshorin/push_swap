#include "push_swap.h"



int				copy_stack(t_stack *a, t_stack *b)
{
	int size;

	size = a->size;
	b->size = size;
	b->data = (int*)malloc(size * sizeof(int));
	if (!a->data || !b->data)
		return (1);
	while (size > 0)
	{
		b->data[size - 1] = a->data[size - 1];
		size--;
	}	
	return (0);
}

int				set_empty_stack(t_stack *a)
{
	a->size = 0;
	return (0);
}



int is_prev_commands_is(t_char_vector *c_vec, char com, size_t size)
{
	size_t i;

	if (size > c_vec->size)
		return (0);
	i = 0;
	while (i < size)
	{
		if (c_vec->data[c_vec->size - 1 - i] != com)
			return (0);
		i++;
	}
	return (1);
}

int c_vector_delete_last_elements(t_char_vector *c_vec, size_t size)
{
	while (size-- > 0)
		c_vector_pop_back(c_vec);
	return (0);
}