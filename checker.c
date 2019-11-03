/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:42:14 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/02 22:42:16 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_ans(t_stack *a, t_stack *b)
{
	if (is_empty(b) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int		check(int argc, char **argv, int flag_v)
{
	t_stack	a;
	t_stack	b;
	char	*buf;
	int		read_size;

	init_stacks(argv, argc, &a, &b);
	if (flag_v)
		exe_command_v("Init", &a, &b, argc);
	while ((read_size = get_next_line(0, &buf)) > 0)
	{
		ft_str_replace(buf, '\n', '\0');
		exe_command(buf, &a, &b);
		if (flag_v)
			exe_command_v(buf, &a, &b, argc);
		free(buf);
	}
	check_ans(&a, &b);
	free_stacks(&a, &b);
	return (0);
}

int		main(int argc, char **argv)
{
	char	**need_free;
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
