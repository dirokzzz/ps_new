#include "checker.h"

void	ft_error(int e)
{
	if (e)
		write(1, "Error\n", 6);
	exit(0);
}

void	print_stacks(t_tab *tab)
{
    int flag;
    t_stack *a = tab->head_a;
    t_stack *b = tab->head_b;
    while (a)
    {
        flag = 0;
        if (a)
        {
            flag = 1;
            ft_printf("%d ", a->index);
            a = a->next;
        }
        if (b)
        {
            if (!flag)
            {
                flag = 1;
                ft_printf("3%d", b->index);
            }
            else
                ft_printf("%d", b->index);
            b = b->next;
        }
        if (flag)
            ft_printf("\n");
    }
    ft_printf("_ _\na b\n");
    /*a = tab->tail_a;
    b = tab->tail_b;
    while (a)
    {
        flag = 0;
        if (a)
        {
            flag = 1;
            ft_printf("%d ", a->index);
            a = a->prev;
        }
        if (b)
        {
            if (!flag)
            {
                flag = 1;
                ft_printf("3%d", b->index);
            }
            else
                ft_printf("%d", b->index);
            b = b->prev;
        }
        if (flag)
            ft_printf("\n");
    }
    ft_printf("_ _\na b\n");*/
}

t_stack *add_elem(t_stack *src, t_stack *dst, t_stack **tail)
{
    t_stack *new;

    if (!src)
        return (dst);
    if (!(new = malloc(sizeof(t_stack))))
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

t_stack *del_elem(t_stack *stack, t_stack **tail)
{
    t_stack *tmp;

    if (!stack)
        return (stack);
    tmp = stack;
    if(stack->next)
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

int check_array(t_tab *tab)
{
	int ok;
    t_stack *a;

    a = tab->head_a;
	ok = 1;
	while(a->next)
	{
		if(a->elem > a->next->elem)
			ok = 0;
		a = a->next;
	}
	if(tab->head_b)
		ok = 0;
	if(ok)
		return (1);
	return (0);
}