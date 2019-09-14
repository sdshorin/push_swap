
#include "push_swap.h"

int		exe_s(t_stack *a)
{
	int temp;

	if (a->size < 2)
		return (0);
	temp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = temp;
	return (0);
}

int		exe_ss(t_stack *a, t_stack *b)
{
	return (exe_s(a) + exe_s(b));
}

int		exe_pa(t_stack *a, t_stack *b)
{
	int temp;

	if (b->size <= 0)
		return (1);
	temp = b->data[0];
	move_stack(b, "r");
	b->size--;
	a->size++;
	move_stack(a, "add");
	a->data[0] = temp;
	return (0);
}

int		exe_ra(t_stack *a)
{
	int temp;

	if (a->size <= 0)
		return (1);
	temp = a->data[0];
	move_stack(a, "r");
	a->data[a->size - 1] = temp;
	return (0);
}

int		exe_rr(t_stack *a, t_stack *b)
{
	exe_ra(a);
	exe_ra(b);
	return (0);
}
