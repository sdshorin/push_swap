#include "libft.h"

int		quick_step(int *num, int first, int last)
{
	int i;
	int j;
	int temp;

	i = first;
	j = last;
	while(i < j)
	{
		while(num[i] <= num[first] && i < last)
			i++;
		while(num[j]>num[first])
			j--;
		if(i < j)
		{
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
		}
	}
}

void ft_quick_sort(int *number,int first,int last)
{
	int j;
	int temp;

	if(first < last)
	{
		j = quick_step(number, first, last);
		temp = number[first];
		number[first] = number[j];
		number[j] = temp;
		quicksort(number,first,j-1);
		quicksort(number,j+1,last);
	}
}
