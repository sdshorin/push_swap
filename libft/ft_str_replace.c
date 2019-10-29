



void	ft_str_replace(char *str, char replace, char to)
{
	while (*str)
	{
		if (*str == replace)
			*str = to;
		str++;
	}
}