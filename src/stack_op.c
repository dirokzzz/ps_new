#include "../includes/checker.h"

t_stack	*add_elem(t_stack *src, t_stack *dst, t_stack **tail)
{
	t_stack *new;

	if (!src)
		return (dst);
	if (!(new = ft_memalloc(sizeof(t_stack))))
		exit(0);
	new->elem = src->elem;
	new->index = src->index;
	if (!dst)
	{
		new->next = NULL;
		new->prev = NULL;
		*tail = new;
		return (new);
	}
	new->next = dst;
	new->prev = NULL;
	dst->prev = new;
	return (new);
}

t_stack	*del_elem(t_stack *stack, t_stack **tail)
{
	t_stack *tmp;

	if (!stack)
		return (stack);
	tmp = stack;
	if (stack->next)
	{
		stack = stack->next;
		stack->prev = NULL;
	}
	else
	{
		*tail = NULL;
		stack = NULL;
	}
	free(tmp);
	return (stack);
}

int		check_array(t_tab *tab)
{
	int		ok;
	t_stack *a;

	a = tab->head_a;
	if (!a)
		return (0);
	ok = 1;
	while (a->next)
	{
		if (a->elem > a->next->elem)
			ok = 0;
		a = a->next;
	}
	if (tab->head_b)
		ok = 0;
	if (ok)
		return (1);
	return (0);
}

void	result(t_tab *t)
{
	int		ok;
	t_stack	*a;

	a = t->head_a;
	ok = 1;
	if (!a)
		ok = 0;
	else
		while (a->next)
		{
			if (a->elem > a->next->elem)
				ok = 0;
			a = a->next;
		}
	if (t->head_b)
		ok = 0;
	if (ok)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
