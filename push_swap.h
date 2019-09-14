
# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"


/*
*	may use lists for optimization
*/

typedef struct	s_stack
{
	int		*data;
	int		size;
}				t_stack;


int				exe_s(t_stack *a);
int				exe_ss(t_stack *a, t_stack *b);
int				exe_pa(t_stack *a, t_stack *b);
int				exe_pb(t_stack *a, t_stack *b);
int				exe_ra(t_stack *a, t_stack *b);
int				exe_rb(t_stack *a, t_stack *b);
int				exe_rr(t_stack *a, t_stack *b);
int				exe_rra(t_stack *a, t_stack *b);
int				exe_rrb(t_stack *a, t_stack *b);
int				exe_rrr(t_stack *a, t_stack *b);


int				move_stack(t_stack *a, int direction);
int				init_stacks(char **input, t_stack *a, t_stack *b);

int				exe_comamd(char *command, t_stack *a, t_stack *b);
int				is_sorted(t_stack a);
int				is_empty(t_stack b);


int				add_command(t_char_vector *c_vec, char *command);


# endif