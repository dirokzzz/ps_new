#include "checker.h"

void	ft_push_b(t_tab *tab)
{
	tab->head_b = add_elem(tab->head_a, tab->head_b, &tab->tail_b);
	tab->head_a = del_elem(tab->head_a, &tab->tail_a);
	tab->message = ft_strjoin_f(tab->message, "pb\n", 1);
}

void	ft_push_a(t_tab *tab)
{
	tab->head_a = add_elem(tab->head_b, tab->head_a, &tab->tail_a);
	tab->head_b = del_elem(tab->head_b, &tab->tail_b);
	tab->message = ft_strjoin_f(tab->message, "pa\n", 1);
}

void	ft_ss(t_tab *tab)
{
	ft_s_elem(tab->head_a, tab, "");
	ft_s_elem(tab->head_b, tab, "");
	ft_printf("ss\n");
}

void	ft_s_elem(t_stack *a, t_tab *tab, char *s)
{
	if (a->next)
	{
		ft_swap_int(&a->elem, &a->next->elem);
		ft_swap_int(&a->index, &a->next->index);
		if (!ft_strcmp("sb", s))
			tab->message = ft_strjoin_f(tab->message, "sb\n", 1);
		if (!ft_strcmp("sa", s))
			tab->message = ft_strjoin_f(tab->message, "sa\n", 1);
	}
}
