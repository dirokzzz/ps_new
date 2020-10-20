#include "../includes/checker.h"

void	re_order(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	if (!a)
		return ;
	tmp = a;
	i = 1;
	while (a)
	{
		a->order = i++;
		a = a->next;
	}
	tmp->size = i - 1;
}

int		direction(t_tab *t, int num)
{
	int		count;
	t_stack	*b;

	b = t->head_b;
	re_order(b);
	count = 0;
	while (b)
	{
		if (b->index == num)
			break ;
		b = b->next;
		count++;
	}
	return (t->head_b->size / 2 - count) <= -1 ? 0 : 1;
}

void	search_num_b(t_tab *t, int num)
{
	if (direction(t, num))
		while (t->head_b->index != num)
			ft_r_stack(t, "rb");
	else
		while (t->head_b->index != num)
			ft_rr_stack(t, "rrb");
}

void	from_a_to_b(t_tab *t)
{
	int max;

	max = t->size;
	while (t->head_b)
	{
		search_num_b(t, max);
		ft_push_a(t);
		max--;
	}
}

void	sort_choise(t_tab *t)
{
	if (t->size <= 3)
		three_num_sort(t);
	if (t->size > 3 && t->size < 10)
		five_num_sort(t);
	if (t->size >= 10 && t->size <= 100)
		sort(t, 5);
	if (t->size > 100)
		sort(t, 11);
}
