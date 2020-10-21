#include "../includes/checker.h"

void	help_print(void)
{
	ft_printf("usage: ./checker [-v] display the stack’s \
	status after each operation\n                 [-s] \
	operations count\n");
	exit(0);
}

void	get_rule_check(t_tab *t)
{
	char	*line;
	int		flag;
	t_rule	*rule;
	int		steps;

	steps = 0;
	if (!(rule = ft_memalloc(sizeof(t_rule))))
		exit(0);
	flag = 1;
	while (get_next_line(0, &line))
	{
		b_zero_rule(rule);
		steps++;
		rule_parse(line, rule);
		rule_accept(t, rule);
		if (t->v)
			print_stacks(t, line);
		free(line);
	}
	if (t->s)
		ft_printf("%d \n", steps);
	result(t);
	free(rule);
}

int		main(int ac, char **av)
{
	t_stack		*a;
	t_tab		*tab;

	a = NULL;
	tab = NULL;
	tab = tab_init(tab);
	if (ac > 1)
	{
		tab->flags = parse_flags(av, ac, tab);
		if (tab->help)
			help_print();
		init_stack_a(a, av, ac, tab);
		get_rule_check(tab);
	}
	free(tab->message);
	free(tab->tab);
	free_stack(tab);
}
