#include "checker.h"

t_stack *ft_r_stack(t_stack *a)
{
    t_stack *current;
    t_stack *first;
    t_stack *last;

    if (!a->index)
        return (a);
    else if(!a->next->index)
        return (a);
    first = a;
    a = a->next;
    current = a;
    while (current->next->next)
        current = current->next;
    last = current;
    first->next = current->next;
    last->next = first;
    return (a); 
}

t_stack *ft_rr_stack(t_stack *a)
{
    t_stack *first;
    t_stack *last;

    if (!a->index)
        return (a);
    else if(!a->next->index)
        return (a);
    first = a;
    while (a->next->next->index)
        a = a->next;
    last = a->next;
    a->next = a->next->next;
    last->next = first;
    return (last);
}