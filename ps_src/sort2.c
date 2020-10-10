#include "checker.h"

int direction(t_tab *t, int num)
{
	int count;
	t_stack *b;

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
	return(t->head_b->size / 2 - count) <= -1 ? 0 : 1;
}

void search_num(t_tab *t, int num)
{
	if(direction(t, num))
		while(t->head_b->index != num)
			ft_r_stack(t, "rb");
	else
		while(t->head_b->index != num)
			ft_rr_stack(t, "rrb");
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