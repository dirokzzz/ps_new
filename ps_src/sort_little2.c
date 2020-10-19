#include "checker.h"

void	five_num(t_tab *t)
{
	int		num;
	int		need;
	t_stack *a;

	a = t->head_a;
	need = 0;
	if (!a || !a->next)
		return ;
	num = t->head_b->index;
	while (a->next)
	{
		if (num > a->index && num < a->next->index)
			need = a->next->index;
		a = a->next;
	}
	if (!need)
		find_min(t);
	else
		search_num_a(t, need);
}

void	five_num_sort(t_tab *t)
{
	t_stack *a;

	a = t->head_a;
	while (t->head_a->next->next->next)
		ft_push_b(t);
	three_num_sort(t);
	while (t->head_b)
	{
		five_num(t);
		ft_push_a(t);
	}
	find_min(t);
}
