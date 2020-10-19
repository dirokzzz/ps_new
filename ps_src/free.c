#include "checker.h"

void	cube_array_free(char ***t)
{
	int x;

	x = 0;
	while (t[x])
		ft_free_array((void**)t[x++]);
	free(t);
}

void	free_stack(t_tab *t)
{
	t_stack *a;
	t_stack *tmp;

	a = t->head_a;
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
