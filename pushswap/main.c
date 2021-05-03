#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_info 
{
	int			a_size;
	int			b_size;
	int			center;
}				t_info ;

void			swap_a(t_info *info, int **dummy)
{
	int			temp;

	if (info->a_size < 2)
		return ;
	temp = (*dummy)[0];
	(*dummy)[0] = (*dummy)[1];
	(*dummy)[1] = temp;
}

void			swap_b(t_info *info, int **dummy)
{
	int			temp;

	if (info->b_size < 2)
		return ;
	temp = (*dummy)[0];
	(*dummy)[0] = (*dummy)[1];
	(*dummy)[1] = temp;
}

void			push_b(t_info *info, int **a, int **b)
{
	int			temp;
	int			i;
	int			len;

	if (info->a_size < 1)
		return ;
	temp = (*a)[0];
	i = 0;
	while (i < info->a_size - 1)
	{
		(*a)[i] = (*a)[i + 1];
		i++;
	}
	i = 0;
	info->a_size--;
	i = info->b_size;
	info->b_size++;
	while (i > 0)
	{
		(*b)[i] = (*b)[i - 1];
		i--;
	}
	(*b)[0] = temp;
}

void			push_a(t_info *info, int **a, int **b)
{
	int			temp;
	int			i;
	int			len;

	if (info->b_size < 1)
		return ;
	temp = (*b)[0];
	i = 0;
	while (i < info->b_size - 1)
	{
		(*b)[i] = (*b)[i + 1];
		i++;
	}
	info->b_size--;
	i = 0;
	len = info->a_size;
	info->a_size++;
	i = len;
	while (i > 0)
	{
		(*a)[i] = (*a)[i - 1];
		i--;
	}
	(*a)[0] = temp;
}

void			rotate_a(t_info *info, int **arr)
{
	int			i;
	int			temp;
	int			len;

	len = info->a_size;
	if (len < 2)
		return ;
	i = 0;
	temp = (*arr)[i];
	while (i < len - 1)
	{
		(*arr)[i] = (*arr)[i + 1];
		i++;
	}
	(*arr)[i] = temp;
}

void			rotate_b(t_info *info, int **arr)
{
	int			i;
	int			temp;
	int			len;

	len = info->b_size;
	if (len < 2)
		return ;
	i = 0;
	temp = (*arr)[i];
	while (i < len - 1)
	{
		(*arr)[i] = (*arr)[i + 1];
		i++;
	}
	(*arr)[i] = temp;
}

int				check_finish(t_info *info, int **arr)
{
	int			i;
	int			len;

	len = info->a_size;
	i = 0;
	while (i < len - 1)
	{
		if ((*arr)[i] > (*arr)[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void			reverse_rotate_a(t_info *info, int **arr)
{
	int			i;
	int			temp;
	int			len;

	len = info->a_size;
	if (len < 2)
		return ;
	i = len - 1;
	temp = (*arr)[i];
	while (i > 0)
	{
		(*arr)[i] = (*arr)[i - 1];
		i--;
	}
	(*arr)[i] = temp;
}

void			reverse_rotate_b(t_info *info, int **arr)
{
	int			i;
	int			temp;
	int			len;

	len = info->b_size;
	if (len < 2)
		return ;
	i = len - 1;
	temp = (*arr)[i];
	while (i > 0)
	{
		(*arr)[i] = (*arr)[i - 1];
		i--;
	}
	(*arr)[i] = temp;
}

int			bubble_sort(t_info *info, int *arr)
{
	int			i;
	int			j;
	int			temp;
	int			len;

	len = info->a_size;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = len / 2;
	return (arr[i]);
}

int			main(int argc, char *argv[])
{
	int			i;
	int			*arr;
	int			idx;
	int			l_s, l_b, r_s, r_b;
	int			*a;
	int			*b;
	char		buf[5];
	int			center;
	t_info		info;

	info.a_size = argc - 1;
	info.b_size = 0;
	a = (int *)malloc(sizeof(int) * (argc - 1));
	b = (int *)malloc(sizeof(int) * (argc - 1));
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	idx = 0;
	while(argv[++i])
	{
		arr[idx] = atoi(argv[i]);
		a[idx++] = atoi(argv[i]);
	}
	center = bubble_sort(&info, arr);
	printf("center = %d\n", center);
	memset(buf, 0, 5);	
	while (read(0, buf, 5))
	{
		if (strcmp(buf, "sa") == 10)
			swap_a(&info, &a);
		if (strcmp(buf, "sb") == 10)
			swap_b(&info, &b);
		if (strcmp(buf, "ss") == 10)
		{
			swap_a(&info, &a);
			swap_b(&info, &b);
		}
		if (strcmp(buf, "pa") == 10)
			push_a(&info, &a, &b);
		if (strcmp(buf, "pb") == 10)
			push_b(&info, &a, &b);
		if (strcmp(buf, "ra") == 10)
			rotate_a(&info, &a);
		if (strcmp(buf, "rb") == 10)
			rotate_b(&info, &b);
		if (strcmp(buf, "rr") == 10)
		{
			rotate_a(&info, &a);
			rotate_b(&info, &b);
		}
		if (strcmp(buf, "rra") == 10)
			reverse_rotate_a(&info, &a);
		if (strcmp(buf, "rrb") == 10)
			reverse_rotate_b(&info, &b);
		if (strcmp(buf, "rrr") == 10)
		{
			reverse_rotate_a(&info, &a);
			reverse_rotate_b(&info, &b);
		}
		printf("---------------\n");
		for (int i = 0; i < info.a_size || i < info.b_size; i++)
		{
			printf("%d  |", i);
			if (i < info.a_size)
				printf("  %d  |", a[i]);
			else
				printf("     |");
			if (i < info.b_size)
				printf("  %d  |\n", b[i]);
			else
				printf("\n");
		}
		printf("---------------");
		printf("\nidx A   B\n");
		printf("---------------");
		if (check_finish(&info, &a) && info.b_size == 0)
		{
			printf("finish!!\n");
			return (0);
		}
		// for (int i = 0; i < info.b_size; i++)
		// {
		// 	printf("B=[%d]", b[i]);
		// 	if (i == info.b_size - 1)
		// 		printf("\n");
		// }
		memset(buf, 0, 5);
	}
	for (int i = 0; i < argc - 1; i++) 
	{
		l_s = 0;
		r_s = 0;
		l_b = 0;
		r_b = 0;
		for (int j = 0; j < i; j++) // 왼쪽 작은
		{
			if (arr[i] > arr[j])
				l_s++;
		}
		for (int j = i + 1; j < argc - 1; j++) // 오른쪽 큰.
		{
			if (arr[i] < arr[j])
				r_b++;
		}
		for (int j = 0; j < i; j++) // 왼쪽 큰
		{
			if (arr[i] < arr[j])
				l_b++;
		}
		for (int j = i + 1; j < argc - 1; j++) // 오른쪽 작은
		{
			if (arr[i] > arr[j])
				r_s++;
		}
		printf("  %d    %d    %d    %d    %d\n", arr[i], l_s, r_s, l_b, r_b);
	}
	i = -1;
	while (arr[++i])
	{
		a[i] = arr[i];
	}
	for (int i = 0; a[i]; i++)
		printf("prev %d\n",a[i]);
	for (int i = 0; i < info.a_size; i++)
		printf("a = %d\n",a[i]);
	for (int i = 0; i < info.b_size; i++)
		printf("1b = %d\n",b[i]);
	return (0);
}