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