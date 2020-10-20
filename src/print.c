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
	*flag = 1;
	ft_printf("%10d ", a->elem);
	return (a->next);
}

void	print_stacks(t_tab *tab)
{
	int		flag;
	t_stack *a;
	t_stack *b;

	a = tab->head_a;
	b = tab->head_b;
	ft_printf("\033[0;31m-----A-----\033[0m|\033[0;32m-----B-----\n\033[0m");
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
