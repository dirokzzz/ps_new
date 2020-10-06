#include "checker.h"

void ft_push_b(t_tab *tab)
{
    tab->head_b = add_elem(tab->head_a, tab->head_b, &tab->tail_b);
    tab->head_a = del_elem(tab->head_a, &tab->tail_a);
    tab->message = ft_strjoin_f(tab->message, "pb\n", 1);
}

void ft_push_a(t_tab *tab)
{
    tab->head_a = add_elem(tab->head_b, tab->head_a, &tab->tail_a);
    tab->head_b = del_elem(tab->head_b, &tab->tail_b);
    tab->message = ft_strjoin_f(tab->message, "pa\n", 1);
}

void ft_ss(t_tab *tab)
{
    ft_s_elem(tab->head_a, "");
    ft_s_elem(tab->head_b, "");
    ft_printf("ss\n");
}

void ft_s_elem(t_stack *a, char *s)
{
    if(a->next->index != 0)
    {
        ft_swap_int(&a->elem, &a->next->elem);
        ft_swap_int(&a->index, &a->next->index);
        if (!ft_strcmp("sb", s))
            ft_printf("sb\n");
        if (!ft_strcmp("sa", s))
            ft_printf("sa\n");
    }
}