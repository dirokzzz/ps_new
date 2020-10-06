#include "checker.h"

int find_max_top(t_tab *t, int part, int *count)
{
	t_stack *a;

	*count = 0;
	a = t->head_b;
	if (!a)
		return (0);
	while (*count <= size_of_stack(a) / 2)
	{
		if (a->index == part)
			return (a->index);
		a = a->next;
		*count = *count + 1;
	}
	return (0);
}

int find_max_bot(t_tab *t, int part, int *count)
{
	t_stack *a;

	*count = 0;
	a = t->tail_b;
	if (!a)
		return (0);
	while (*count <= size_of_stack(t->head_b) / 2)
	{
		if(a->index == part)
			return (a->index);
		a = a->prev;
		*count = *count + 1;
	}
	return (0);
}

char *find_max(t_tab *t, int max)
{
	int count_t;
	int count_b;

	find_max_top(t, max, &count_t);
	find_max_bot(t, max, &count_b);
	return (count_t <= count_b ? "r" : "rr");
}

int search_num(t_tab *t, int num)
{
	int flag;

	flag = 0;
	if (t->head_b)
	{
		if (!ft_strcmp("r", find_max(t, num)))
		{
			flag = 1;
			while (t->head_b->index != num)
				ft_r_stack(t, "rb");
		}
		if (!ft_strcmp("rr", find_max(t, num)))
		{
			flag = 1;
			while (t->head_b->index != num)
				ft_rr_stack(t, "rrb");	
		}
	}
	return (flag ? 1 : 0);
}

void from_a_to_b(t_tab *t)
{
	int max;

	max = t->size;
	while(t->head_b)
	{
		search_num(t, max);
		ft_push_a(t);
		max--;
	}
}