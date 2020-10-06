#include <stdlib.h>
#include <stdio.h>
#include "ps_src/checker.h"


void ft_clearstr_stack(t_tab *s)
{
	char *ptr;

	ptr = s->message;
	char *str;
    while (*ptr != '\0')
    {
        if (ft_strncmp(ptr, "pa\npb\n", 6) == 0)
        {
            ft_strcpy(ptr, (ptr + 6));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "pb\npa\n", 6) == 0)
        {
            ft_strcpy(ptr, (ptr + 6));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "\nrb\nrrb", 7) == 0)
        {
            ft_strcpy(ptr, (ptr + 7));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "ra\nrb\n", 4) == 0)
        {
			str = ft_strdup(ptr + 6);
            ft_strcpy(ptr, "rr\n");
			ptr = s->message;
			ptr = ft_strjoin_f(ptr, str, 1);
			s->message = ptr;
        }
        else
            ptr++;
    }
}

int main()
{
	t_tab *a;

	a = malloc(sizeof(t_tab));
	a->message = ft_strdup("!!!!!!!!!!!ra\nrb\n!!!!!!!!!!");
	ft_clearstr_stack(a);
	printf("%s\n", a->message);
	free(a->message);
	free(a);
}



void min_to_top_b(t_tab *t)
{
	int num;
	int need;
	t_stack *b;

	need = 0;
	if (!b || !b->next)
		return ;
	num = t->head_a->index;
	while (b)
	{
		if(num < b->index && num > b->next->index)
			need = b->index;
		b = b->next;
	}
	if(!need)
	{
		
	}
}

void min_to_top_b(t_tab *t)
{
	int		min;
	t_stack *a;
	int		size;
	int		order;

	if(!t->head_b)
		return ;
	a = t->head_b;
	size = a->size;
	min = INT32_MAX;
	re_order(t->head_b);
	while(a)
	{
		min = min > a->index ? a->index : min;
		a = a->next;
	}
	a = t->head_b;
	while(a->index != min)
		a = a->next;
	order = a->order;
	to_top_b(t, min, order);
}