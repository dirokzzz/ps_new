#include "checker.h"

int size_of_stack(t_stack *a)
{
	int i;

	i = 0;
	while(a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void re_order(t_stack *a)
{
	int i;
	t_stack *tmp;

	if (!a)
		return ;
	tmp = a;
	i = 1;
	while(a)
	{
		a->order = i++;
		a = a->next;
	}
	tmp->size = i - 1;
}

int find_num_top(t_tab *t, int part, int *count)
{
	t_stack *a;

	*count = 0;
	a = t->head_a;
	if (!a)
		return (0);
	while (*count <= size_of_stack(a) / 2)
	{
		if (a->index <= part)
			return (a->order);
		a = a->next;
		*count = *count + 1;
	}
	return (0);
}

int find_num_bot(t_tab *t, int part, int *count)
{
	t_stack *a;

	*count = 0;
	a = t->tail_a;
	if (!a)
		return (0);
	while (*count <= size_of_stack(t->head_a) / 2)
	{
		if(a->index <= part)
			return (a->order);
		a = a->prev;
		*count = *count + 1;
	}
	return (0);
}

char *find_num(t_tab *t, int part)
{
	int top;
	int bottom;
	int count_t;
	int count_b;

	top = find_num_top(t, part, &count_t);
	bottom = find_num_bot(t, part, &count_b);
	if(!top && !bottom)
		return("");
	t->num = (count_t >= count_b) ? bottom : top;
	if(t->num <= (t->size / 2))
		return("r");
	else
		return("rr");
}

int num_to_top(t_tab *t, char c, int part)
{
	int flag;

	flag = 0;
	if (c == 'a' && t->head_a)
	{
		if (!ft_strcmp("r", find_num(t, part)))
		{	
			flag = 1;
			while (t->head_a->order != t->num)
			{	
				ft_r_stack(t, "ra");
			}
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

void find_min(t_tab *t)
{
	t_stack *a;
	int min;

	min = INT32_MAX;
	a = t->head_b;
	while (a)
	{
		min = min > a->index ? a->index : min;
		a = a->next;
	}
	search_num(t, min);
}

void two_num(t_tab *t)
{
	t_stack *b;

	b = t->head_b;
	if(b->index > b->next->index)
		ft_s_elem(b, t, "sb");
}

void to_top_b(t_tab *t)
{
	int num;
	int need;
	t_stack *b;

	b = t->head_b;
	need = 0;
	if (!b || !b->next)
		return ;
	if (!b->next->next)
		two_num(t);
	num = t->head_a->index;
	while (b->next)
	{		
		if(num > b->index && num < b->next->index)
			need = b->next->index;
		b = b->next;
	}
	if(!need)
		find_min(t);
	else
		search_num(t, need);
}

void sort(t_tab *t)
{
	int part;
	
	part = t->size / 10;
	while(t->head_a)
	{
		while(num_to_top(t, 'a', part))
		{
			to_top_b(t);
			ft_push_b(t);
			re_order(t->head_a);
		}
		part += t->size / 10;
	}
	from_a_to_b(t);
}
