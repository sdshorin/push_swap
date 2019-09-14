#include "push_swap.h"

int check_ans(t_stack *a, t_stack *b)
{
	if (is_empty(b) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int main(int argc, char **argv)
{
	int flag_v;
	t_stack a;
	t_stack b;
	char	buf[5];
	int		read_size;

	argv++;
	flag_v = 0;
	if (argc < 2)
		return (0);
	if (!ft_strcmp(argv[0], "-v"))
	{
		flag_v = 1;
		argv++;
		argc--;
	}
	init_stacks(argv, argc - 1, &a, &b, flag_v);
	while ((read_size = read(0, buf, 5)) > 0)
	{
		buf[read_size] = '\0';
		exe_command(buf, &a, &b);
		if (flag_v)
			exe_command_v(buf, &a, &b, argc - 1);
	}
	check_ans(&a, &b);
}
