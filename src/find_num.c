#include "../includes/checker.h"

int		find_num_top(t_tab *t, int part, int *count)
{
	t_stack *a;

	*count = 0;
	a = t->head_a;
	if (!a)
		return (0);
	while (*count <= (size_of_stack(t->head_a) / 2))
	{
		if (a->index <= part)
			return (a->order);
		a = a->next;
		*count = *count + 1;
	}
	return (0);
}

int		find_num_bot(t_tab *t, int part, int *count)
{
	t_stack *a;

	*count = 0;
	a = t->tail_a;
	if (!a)
		return (0);
	while (*count <= (size_of_stack(t->head_a) / 2))
	{
		if (a->index <= part)
			return (a->order);
		a = a->prev;
		*count = *count + 1;
	}
	return (0);
}

char	*find_num(t_tab *t, int part)
{
	int top;
	int bottom;
	int count_t;
	int count_b;

	re_order(t->head_a);
	top = find_num_top(t, part, &count_t);
	bottom = find_num_bot(t, part, &count_b);
	if (!top && !bottom)
		return ("");
	t->num = (count_t >= count_b) ? bottom : top;
	if (t->num <= (t->head_a->size / 2))
		return ("r");
	else
		return ("rr");
}

int		num_to_top(t_tab *t, int part)
{
	int flag;

	flag = 0;
	if (t->head_a)
	{
		if (!ft_strcmp("r", find_num(t, part)))
		{
			flag = 1;
			while (t->head_a->order != t->num)
				ft_r_stack(t, "ra");
		}
		else if (!ft_strcmp("rr", find_num(t, part)))
		{
			flag = 1;
			while (t->head_a->order != t->num)
				ft_rr_stack(t, "rra");
		}
	}
	return (flag);
}

void	b_zero_rule(t_rule *rule)
{
	rule->sa = 0;
	rule->sb = 0;
	rule->ss = 0;
	rule->pa = 0;
	rule->pb = 0;
	rule->ra = 0;
	rule->rb = 0;
	rule->rr = 0;
	rule->rra = 0;
	rule->rrb = 0;
	rule->rrr = 0;
}
