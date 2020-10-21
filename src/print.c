#include "../includes/checker.h"

t_stack	*print_b(t_stack *b, int *flag)
{
	if (*flag == 0)
	{
		*flag = 1;
		ft_printf("%10d", b->elem);
	}
	else
		ft_printf("%10d", b->elem);
	return (b->next);
}

t_stack	*print_a(t_stack *a, int *flag)
{
	char *color;

	if (!a->prev)
		color = (a->index == a->next->index - 1) ? C(GREEN) : C(RED);
	else
		color = (a->index == a->prev->index + 1) ? C(GREEN) : C(RED);
	*flag = 1;
	ft_printf("%s", color);
	ft_printf("%10d "C(NO), a->elem);
	return (a->next);
}

void print(t_stack *a, t_stack *b)
{
	int flag;

	while (a || b)
	{
		flag = 0;
		if (a)
			a = print_a(a, &flag);
		if (flag)
			ft_printf("|");
		else
			ft_printf("           |");
		if (b)
			b = print_b(b, &flag);
		if (flag)
			ft_printf("\n");
	}
}

void	print_stacks(t_tab *tab, char *line)
{
	t_stack *a;
	t_stack *b;

	a = tab->head_a;
	b = tab->head_b;
	ft_printf(C(GRBL)"-----A-----"C(NO));
	ft_printf("|");
	ft_printf(C(BLUE)"-----B-----\n"C(NO));
	print(a, b);
	ft_printf("-----------------------\n");
	if (line)
		ft_printf(C(YELLOW)"%s\n"C(NO), line);
}
