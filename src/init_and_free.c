#include "../includes/checker.h"

void	cube_array_free(char ***t)
{
	int x;

	x = 0;
	while (t[x])
		ft_free_array((void**)t[x++]);
	free(t);
}

void	free_stack(t_tab *t)
{
	t_stack *a;
	t_stack *tmp;

	if (t->head_a)
	{
		a = t->head_a;
		while (a)
		{
			tmp = a;
			a = a->next;
			free(tmp);
		}
	}
	if (t->head_b)
	{
		a = t->head_b;
		while (a)
		{
			tmp = a;
			a = a->next;
			free(tmp);
		}
	}
}

t_stack	*new_elem(t_stack *stack, int elem)
{
	t_stack *new;

	if (!(new = malloc(sizeof(t_stack))))
		exit(0);
	stack->next = new;
	new->elem = elem;
	new->next = NULL;
	new->prev = stack;
	return (new);
}

t_stack	*index_init(t_stack *a, t_tab *tab)
{
	t_stack	*head;
	int		i;

	head = a;
	i = 0;
	sort_int_tab(tab->tab, tab->size);
	while (i < tab->size && a)
	{
		if (tab->tab[i] == a->elem)
		{
			a->index = i + 1;
			i = -1;
			a = a->next;
		}
		i++;
	}
	return (head);
}

void	init_stack_a(t_stack *stack, char **av, int ac, t_tab *tab)
{
	int	x;

	x = 0;
	tab->size = size_of_tab(ac, av, tab);
	tab->tab = parse_args(ac, av, tab);
	if (!(stack = malloc(sizeof(t_stack))))
		exit(0);
	tab->head_a = stack;
	stack->elem = tab->tab[x++];
	stack->order = x;
	stack->prev = NULL;
	while (x < tab->size)
	{
		stack = new_elem(stack, tab->tab[x++]);
		stack->order = x;
		tab->tail_a = stack;
	}
	if (tab->size == 1)
	{
		ft_printf("OK\n");
		exit(0);
	}
	tab->head_a = index_init(tab->head_a, tab);
	check_dubble(tab->head_a);
}
