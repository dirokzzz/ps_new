#include "checker.h"

void ft_r_stack(t_tab *tab, char *s) //OK
{
    t_stack *a;
    t_stack *current;
    t_stack *first;
    t_stack *last;

    a = tab->head_a;
    if (!a || !a->next)
        return ;
    first = a;
    a = a->next;
    a->prev = NULL;
    current = a;
    while(current->next)
        current = current->next;
    last = current;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    tab->tail_a = first;
    if (!ft_strcmp("rb", s))
        ft_printf("rb\n");
    if (!ft_strcmp("ra", s))
        ft_printf("ra\n");
    tab->head_a = a;
}

void ft_rr_stack(t_tab *tab, char *s)//OK
{
    t_stack *first;
    t_stack *last;
    t_stack *a;

    a = tab->head_a;
    if (!a || !a->next)
        return ;
    first = a;
    while (a->next->next)
        a = a->next;
    last = a->next;
    a->next = NULL;
    last->next = first;
    first->prev = last;
    last->prev = NULL;
    tab->tail_a = a;
    if (!ft_strcmp(s, "rrb"))
        ft_printf("rrb\n");
    else if (!ft_strcmp(s, "rra"))
        ft_printf("rra\n");
    tab->head_a = last;
}

void    ft_rrr(t_tab *tab, char *s)
{
    ft_rr_stack(tab, s);
    ft_rr_stack(tab, s);
}

void    ft_rr(t_tab *tab, char *s)
{
    ft_r_stack(tab, s);
    ft_r_stack(tab, s);
    if (ft_strcmp("rr", s))
        ft_printf("rr\n");
}