#include "push_swap.h"

int check_ans(t_stack *a, t_stack *b)
{
	if (is_empty(b) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	check(int argc, char **argv, int flag_v)
{
	t_stack a;
	t_stack b;
	char	*buf;
	int		read_size;

	
	
	init_stacks(argv, argc, &a, &b, flag_v);
	// while ((read_size = read(0, buf, 5)) > 0)
	while ((read_size = get_next_line(0, &buf)) > 0)
	{
		// buf[read_size] = '\0';
		// replase \n to \0, delete extra strcmp in exe_command
		exe_command(buf, &a, &b);
		if (flag_v)
			exe_command_v(buf, &a, &b, argc);
	}
	check_ans(&a, &b);
	return (0);
}


int main(int argc, char **argv)
{
	char 	**need_free;
	int		flag_v;

	flag_v = 0;
	need_free = NULL;
	argv++;
	if (argc-- < 2)
		return (0);
	if (!ft_strcmp(argv[0], "-v"))
	{
		flag_v = 1;
		argv++;
		argc--;
	}
	if (argc == 1)
	{
		argc = words_counter(*argv, ' ');
		argv = ft_strsplit(*argv, ' ');
		need_free = argv;
	}
	check(argc, argv, flag_v);
	if (need_free)
		delete_str_array(need_free);
}
