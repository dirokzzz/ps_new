#include "checker.h"

void	stack_choise(t_tab *t, t_stack *tail, t_stack *head, char *s)
{
	if (!ft_strcmp(s, "rb") || !ft_strcmp(s, "rrb"))
	{
		t->tail_b = tail;
		t->head_b = head;
	}
	if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rra"))
	{
		t->tail_a = tail;
		t->head_a = head;
	}
}

void	ft_r_stack(t_tab *tab, char *s)
{
	t_stack *a;
	t_stack *current;
	t_stack *first;
	t_stack *last;

	a = !ft_strcmp(s, "rb") ? tab->head_b : tab->head_a;
	if (!a || !a->next)
		return ;
	first = a;
	a = a->next;
	a->prev = NULL;
	current = a;
	while (current->next)
		current = current->next;
	last = current;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	stack_choise(tab, first, a, s);
	if (!ft_strcmp("rb", s))
		tab->message = ft_strjoin_f(tab->message, "rb\n", 1);
	if (!ft_strcmp("ra", s))
		tab->message = ft_strjoin_f(tab->message, "ra\n", 1);
}

void	ft_rr_stack(t_tab *tab, char *s)
{
	t_stack *first;
	t_stack *last;
	t_stack *a;

	a = !ft_strcmp(s, "rrb") ? tab->head_b : tab->head_a;
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
	stack_choise(tab, a, last, s);
	if (!ft_strcmp(s, "rrb"))
		tab->message = ft_strjoin_f(tab->message, "rrb\n", 1);
	else if (!ft_strcmp(s, "rra"))
		tab->message = ft_strjoin_f(tab->message, "rra\n", 1);
}

void	ft_rrr(t_tab *tab, char *s)
{
	ft_rr_stack(tab, s);
	ft_rr_stack(tab, s);
}

void	ft_rr(t_tab *tab, char *s)
{
	ft_r_stack(tab, s);
	ft_r_stack(tab, s);
	if (ft_strcmp("rr", s))
		tab->message = ft_strjoin_f(tab->message, "rr\n", 1);
}
