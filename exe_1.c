
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




int				exe_pa(t_stack *a, t_stack *b);
int				exe_pb(t_stack *a, t_stack *b);