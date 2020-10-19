#include "checker.h"

int		size_of_stack(t_stack *a)
{
	int i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	find_max_b(t_tab *t)
{
	t_stack *a;
	int		max;

	max = INT32_MIN;
	a = t->head_b;
	while (a)
	{
		max = max < a->index ? a->index : max;
		a = a->next;
	}
	search_num_b(t, max);
}

void	to_top_b(t_tab *t)
{
	int		num;
	int		need;
	t_stack *b;

	b = t->head_b;
	need = 0;
	if (!b || !b->next)
		return ;
	num = t->head_a->index;
	if (num > b->index && num < t->tail_b->index)
		return ;
	while (b->next)
	{
		if (num < b->index && num > b->next->index)
			need = b->next->index;
		b = b->next;
	}
	if (!need)
		find_max_b(t);
	else
		search_num_b(t, need);
}

void	sort(t_tab *t, int del)
{
	int part;

	part = t->size / del;
	while (t->head_a)
	{
		while (num_to_top(t, part))
		{
			to_top_b(t);
			ft_push_b(t);
			re_order(t->head_a);
		}
		part += t->size / del;
	}
	from_a_to_b(t);
}
