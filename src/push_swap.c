#include "../includes/checker.h"

void	ft_clearstr_stack(t_tab *s)
{
	char *ptr;

	ptr = s->message;
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
		else
			ptr++;
	}
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_tab		*tab;

	a = NULL;
	tab = NULL;
	tab = tab_init(tab);
	if (ac > 2)
	{
		init_stack_a(a, av, ac, tab);
		tab->head_b = NULL;
		tab->tail_b = NULL;
		if (!check_array(tab))
			sort_choise(tab);
		ft_clearstr_stack(tab);
		ft_printf("%s", tab->message);
	}
	free(tab->message);
	free(tab->tab);
	free(tab);
	free_stack(tab);
}
