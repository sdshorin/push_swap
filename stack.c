#include "push_swap.h"


int				move_stack(t_stack *a, int direction)
{
	int		size;
	int		now;

	now = 0;
	size = a->size - 1;
	if (!size)
		return (0);
	if (direction)
	{
		while (now < size)
		{
			a->data[now] = a->data[now + 1];
			now++;
		}
		return (0);
	}
	while (0 <= size - 1)
	{
		a->data[size] = a->data[size - 1];
		now++;
	}
	return (0);
}


int				init_stacks(char **input, t_stack *a, t_stack *b);
