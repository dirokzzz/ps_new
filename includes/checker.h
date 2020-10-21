#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>

# define COLOR
# define RED			"31"
# define GREEN			"32"
# define YELLOW			"33"
# define BLUE			"34"
# define PINK			"35"
# define GRBL			"36"
# define GREY			"37"
# define NO				"0"
# define C(X)			"\033["X"m"

typedef struct	s_stack
{
	int				elem;
	int				index;
	int				order;
	int				size;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_rule
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}				t_rule;

typedef struct	s_tab
{
	int		*tab;
	int		size;
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
	char	*message;
	int		s;
	int		v;
	int		vs;
	int		help;
	int		flags;
	int		num;
}				t_tab;

int			size_of_stack(t_stack *a);
int			num_to_top(t_tab *t, int part);
int			check_array(t_tab *t);
int			size_of_tab(int ac, char **av, t_tab *t);
int			*parse_args(int ac, char **av, t_tab *tab);
int			parse_flags(char **av, int ac, t_tab *t);
void		sort_int_tab(int *tab, int size);
void		rule_accept(t_tab *t, t_rule *rule);
void		rule_parse(char *line, t_rule *rule);
void		result(t_tab *t);
void		b_zero_rule(t_rule *rule);
void		check_dubble(t_stack *a);
void		search_num_a(t_tab *t, int num);
void		five_num_sort(t_tab *t);
void		three_num_sort(t_tab *tab);
void		free_stack(t_tab *t);
void		cube_array_free(char ***t);
void		to_top_b(t_tab *t);
void		re_order(t_stack *a);
void		find_min(t_tab *t);
void		search_num_b(t_tab *t, int num);
char		*find_max(t_tab *t, int max);
void		from_a_to_b(t_tab *t);
void		min_to_top_b(t_tab *t);
void		sort(t_tab *t, int del);
char		*find_num(t_tab *t, int part);
void		sort_int_tab(int *tab, int size);
void		sort_processing(t_tab *tab);
void		ft_error(int e);
void		print_stacks(t_tab *tab, char *line);
void		get_rule_check(t_tab *t);
void		check_arg(int ac, char **av, t_tab *t);
void		ft_s_elem(t_stack *a, t_tab *tab, char *s);
void		ft_ss(t_tab *tab);
void		ft_push_a(t_tab *tab);
void		ft_push_b(t_tab *tab);
void		ft_r_stack(t_tab *tab, char *s);
void		ft_rr_stack(t_tab *tab, char *s);
void		ft_rrr(t_tab *tab);
void		ft_rr(t_tab *tab);
void		sort_choise(t_tab *t);
void		init_stack_a(t_stack *stack, char **av, int ac, t_tab *tab);
t_tab		*tab_init(t_tab *t);
t_stack		*index_init(t_stack *a, t_tab *tab);
t_stack		*new_elem(t_stack *stack, int elem);
t_stack		*del_elem(t_stack *stack, t_stack **tail);
t_stack		*add_elem(t_stack *src, t_stack *dst, t_stack **tail);

#endif
