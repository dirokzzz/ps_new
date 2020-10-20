#include "../includes/checker.h"

void	save_index(t_tab *tab, int *a, int *b, int *c)
{
	*a = tab->head_a->index;
	*b = tab->head_a->next->index;
	*c = !tab->head_a->next->next ? 0 : tab->head_a->next->next->index;
}

void	three_num_sort(t_tab *tab)
{
	int a;
	int b;
	int c;

	save_index(tab, &a, &b, &c);
	if (!c)
	{
		if (b < a)
			ft_s_elem(tab->head_a, tab, "sa");
		return ;
	}
	if ((a > b && a < c) || (b > c && b < a)\
	|| (c < b && c > a))
	{
		ft_s_elem(tab->head_a, tab, "sa");
		save_index(tab, &a, &b, &c);
	}
	if (a < b && a > c)
		ft_rr_stack(tab, "rra");
	if (c > b && a > c)
		ft_r_stack(tab, "ra");
}

int		direction_a(t_tab *t, int num)
{
	int		count;
	t_stack	*a;

	a = t->head_a;
	re_order(a);
	count = 0;
	while (a)
	{
		if (a->index == num)
			break ;
		a = a->next;
		count++;
	}
	return (t->head_a->size / 2 - count) <= -1 ? 0 : 1;
}

void	search_num_a(t_tab *t, int num)
{
	if (direction_a(t, num))
		while (t->head_a->index != num)
			ft_r_stack(t, "ra");
	else
		while (t->head_a->index != num)
			ft_rr_stack(t, "rra");
}

void	find_min(t_tab *t)
{
	t_stack	*a;
	int		min;

	min = INT32_MAX;
	a = t->head_a;
	while (a)
	{
		min = min > a->index ? a->index : min;
		a = a->next;
	}
	search_num_a(t, min);
}
