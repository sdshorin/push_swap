
#include "push_swap.h"


int		error()
{
	write(1, "Error\n", 6);
	exit(1);
}



int		exe_comamd(char *command, t_stack *a, t_stack *b)
{
	if (ft_strcmp(command, "sa"))
		return (exe_s(a));
	else if (ft_strcmp(command, "sb"))
		return (exe_s(b));
	else if (ft_strcmp(command, "ss"))
		return (exe_ss(a, b));
	else if (ft_strcmp(command, "pa"))
		return (exe_pa(a, b));
	else if (ft_strcmp(command, "pb"))
		return (exe_pb(a, b));
	else if (ft_strcmp(command, "ra"))
		return (exe_ra(a, b));
	else if (ft_strcmp(command, "rb"))
		return (exe_rb(a, b));
	else if (ft_strcmp(command, "rr"))
		return (exe_rr(a, b));
	else if (ft_strcmp(command, "rra"))
		return (exe_rra(a, b));
	else if (ft_strcmp(command, "rrb"))
		return (exe_rrb(a, b));
	else if (ft_strcmp(command, "rrr"))
		return (exe_rrr(a, b));
	else 
		return error();
}
