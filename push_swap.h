
# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"


# include <stdio.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

/*
*	may use lists for optimization
*/

typedef struct	s_stack
{
	int		*data;
	int		size;
	char	type;
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

int				find_sep(t_stack *a, int len);
int 			is_stack_sorted_up(t_stack *a, int size);
int				is_stack_sorted_down(t_stack *a, int size);


int				sort_step_up(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				sort_step_down(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				divide_stack(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				divide_stack_down(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				sort_short_part_up(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				sort_short_part_down(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				first_divide_stack_v_2(t_stack *a, t_stack *b, int len, t_char_vector *commands);
int				return_stack(t_stack *a, t_stack *b, int size_a, t_char_vector *commands);
int				set_empty_stack(t_stack *a);
int				copy_stack(t_stack *a, t_stack *b);

void			add_command(t_stack *a, t_stack *b, t_char_vector *c_vec, char *command);
int				add_commands(t_stack *a, t_stack *b, t_char_vector *c_vec, char *commands);

int is_prev_commands_is(t_char_vector *c_vec, char com, size_t size);
int c_vector_delete_last_elements(t_char_vector *c_vec, size_t size);

int		print_ans(t_char_vector *ans);


# endif