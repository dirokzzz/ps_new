#include "../includes/checker.h"

void	ft_error(int e)
{
	if (e)
		ft_printf("Error\n");
	exit(0);
}

void	check_arg(int ac, char **av, t_tab *t)
{
	int i;
	int j;

	i = 1;
	if (t->flags)
		i++;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < 48 || av[i][j] > 57) && av[i][j]\
			!= ' ' && av[i][j] != '-' && av[i][j] != '+')
				ft_error(5);
			else if ((av[i][j] == '-' || av[i][j] == '+') &&\
			(av[i][j + 1] < 48 || av[i][j + 1] > 57))
				ft_error(6);
			j++;
		}
		i++;
	}
}

void	rule_accept(t_tab *t, t_rule *rule)
{
	if (rule->rb)
		ft_r_stack(t, "rb");
	else if (rule->rr)
		ft_rr(t);
	else if (rule->rra)
		ft_rr_stack(t, "rra");
	else if (rule->rrb)
		ft_rr_stack(t, "rrb");
	else if (rule->rrr)
		ft_rrr(t);
	else if (rule->pa)
		ft_push_a(t);
	else if (rule->pb)
		ft_push_b(t);
	else if (rule->sa)
		ft_s_elem(t->head_a, t, "sa");
	else if (rule->sb)
		ft_s_elem(t->head_b, t, "sb");
	else if (rule->ss)
		ft_ss(t);
	else if (rule->ra)
		ft_r_stack(t, "ra");
}

void	rule_parse(char *line, t_rule *rule)
{
	if (!ft_strcmp(line, "sa"))
		rule->sa = 1;
	else if (!ft_strcmp(line, "sb"))
		rule->sb = 1;
	else if (!ft_strcmp(line, "ss"))
		rule->ss = 1;
	else if (!ft_strcmp(line, "pa"))
		rule->pa = 1;
	else if (!ft_strcmp(line, "pb"))
		rule->pb = 1;
	else if (!ft_strcmp(line, "ra"))
		rule->ra = 1;
	else if (!ft_strcmp(line, "rb"))
		rule->rb = 1;
	else if (!ft_strcmp(line, "rrb"))
		rule->rrb = 1;
	else if (!ft_strcmp(line, "rrr"))
		rule->rrr = 1;
	else if (!ft_strcmp(line, "rr"))
		rule->rr = 1;
	else if (!ft_strcmp(line, "rra"))
		rule->rra = 1;
	else
		ft_error(1);
}
