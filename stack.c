#include "push_swap.h"


int		move_stack(t_stack *a, char *direction)
{
	int		size;
	int		now;

	now = 0;
	size = a->size - 1;
	if (!size)
		return (0);
	if (!ft_strcmp(direction, "r"))
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
		size--;
	}
	int l[10];
	for (int i = a->size - 1; i>=0; i--)
		l[i] = a->data[i];
	l[8] = 6;

	return (0);
}

int		is_correct_input(char *str)
{
	int			num;
	long long	num_2;
	int			sig;

	num = 0;
	num_2 = 0;
	sig = 1;
	if (!*str || !ft_strcmp(str, "-"))
		return (0);
	if (*str == '-' && str++)
		sig = -1;
	while(ft_isdigit(*str))
	{
		num_2 = num_2 * 10 + sig * (*str - '0');
		num = num * 10 + sig * (*str - '0');
		if (num != num_2)
			return (0);
		str++;
	}
	if (*str)
		return (0);
	return (1);
}



int		error(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	write(1, "Error\n", 6);
	exit(1);
}


int		init_stacks(char **input, int len, t_stack *a,\
									t_stack *b, int flag_v)
{
	int size;
	int i;

	size = len;
	a->data = (int*)malloc(len * sizeof(int));
	a->size = len;
	b->data = (int*)malloc(len * sizeof(int));
	if (!a->data || !b->data)
		return (1);
	while (len > 0)
	{
		if (!is_correct_input(input[len - 1]))
			return error(a, b);
		a->data[len - 1] = ft_atoi(input[len - 1]);
		i = len;
		while (i < size)
			if (a->data[len - 1] == a->data[i++])
				return error(a, b);
		len--;
	}	
	if (flag_v)
		exe_command_v("Init", a, b, size);
	return (0);
}
