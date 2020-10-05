#include "checker.h"

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
	int 	i;

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

t_stack	*init_stack_a(t_stack *stack, char **av, int ac, t_tab *tab)
{
	int     x;
	t_stack *head;

	x = 0;
	tab->size = size_of_tab(ac, av);
	tab->tab = parse_args(ac, av);
	if (!(stack = malloc(sizeof(t_stack))))
	    exit(0);
	head = stack;
	stack->elem = tab->tab[x++];
	stack->index = x;
	stack->prev = NULL;
	while (x < tab->size)
	{
	    stack = new_elem(stack, tab->tab[x++]);
	    stack->index = x;
	    tab->tail_a = stack;
	}
	head = index_init(head, tab);
	return (head);
}

int		main(int ac, char **av)
{
    t_stack     *a;
    t_tab       *tab;
    
    if (!(tab = malloc(sizeof(t_tab))))
        exit(0);
    tab->bottom = 0;
    a = NULL;
    if (ac >= 2)
    {
        tab->head_a = init_stack_a(a, av, ac, tab);
        tab->head_b = NULL;
		tab->tail_b = NULL;
		print_stacks(tab);
		getchar();
		ft_push_b(tab);
		print_stacks(tab);
		getchar();
		ft_push_b(tab);
		print_stacks(tab);
		getchar();
		ft_push_a(tab);
		print_stacks(tab);
		getchar();
		ft_push_a(tab);
		print_stacks(tab);
		getchar();
		ft_push_a(tab);
		print_stacks(tab);
		getchar();
        tab->top = tab->size / 2 + 1;
        if (!check_array(tab))
			printf("qwqeqe");
          //  sort_processing(tab);
    }
    free(tab);
}
