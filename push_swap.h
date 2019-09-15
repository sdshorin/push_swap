
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
int				exe_ra(t_stack *a);
int				exe_rr(t_stack *a, t_stack *b);
int				exe_rra(t_stack *a);
int				exe_rrr(t_stack *a, t_stack *b);


int				move_stack(t_stack *a, char *direction);
int				init_stacks(char **input, int len, t_stack *a, t_stack *b, int flag_v);
int				free_stacks(t_stack *a, t_stack *b);
int				is_sorted(t_stack *a);
int				is_empty(t_stack *b);
int				is_no_duplicate(t_stack *b);


int				error(t_stack *a, t_stack *b);

int				exe_command(char *command, t_stack *a, t_stack *b);
int 			exe_command_v(char *command, t_stack *a, t_stack *b, int len);


int				sort_step_up(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				sort_step_down(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				divide_stack(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				sort_short_part_up(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				sort_short_part_v_2(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				first_divide_stack_v_2(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				return_stack(t_stack *a, t_stack *b, int size_a, t_char_vector *commands);

int				add_command(t_stack *a, t_stack *b, t_char_vector *c_vec, char *command);




# endif