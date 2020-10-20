#include "../includes/checker.h"

void	check_dubble(t_stack *a)
{
	t_stack *head;
	t_stack *current;

	head = a;
	current = a;
	while (current)
	{
		while (a)
		{
			if (current->elem == a->elem && current->order != a->order)
				ft_error(3);
			a = a->next;
		}
		a = head;
		current = current->next;
	}
}

int		cmp_arg(char **av)
{
	if (!ft_strcmp(&av[1][0], "-v"))
		return (1);
	else if (!ft_strcmp(&av[1][0], "-vs"))
		return (1);
	else if (!ft_strcmp(&av[1][0], "-sv"))
		return (1);
	else if (!ft_strcmp(&av[1][0], "-s"))
		return (1);
	else if (!ft_strcmp(&av[1][0], "-help"))
		return (1);
	else
		return (0);
}

int		parse_flags(char **av, int ac, t_tab *t)
{
	if (cmp_arg(av))
	{
		if (!ft_strcmp(&av[1][0], "-v"))
			t->v = 1;
		if (!ft_strcmp(&av[1][0], "-vs") || !ft_strcmp(&av[1][0], "-sv"))
		{
			t->s = 1;
			t->v = 1;
		}
		if (!ft_strcmp(&av[1][0], "-s"))
			t->s = 1;
		if (!ft_strcmp(&av[1][0], "-help"))
			t->help = 1;
		if (t->help && ac > 2)
			ft_error(1);
		return (1);
	}
	return (0);
}

t_tab	*tab_init(t_tab *t)
{
	if (!(t = malloc(sizeof(t_tab))))
		exit(0);
	t->message = ft_strdup("");
	t->v = 0;
	t->vs = 0;
	t->s = 0;
	t->help = 0;
	t->flags = 0;
	return (t);
}

void	sort_int_tab(int *tab, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			ft_swap_int(&tab[i], &tab[i - 1]);
			i = 0;
		}
		i++;
	}
}
