#include "../includes/checker.h"

char	***split_args(int ac, char **av, t_tab *t)
{
	int		i;
	char	***args;
	int		y;

	args = (char***)malloc(sizeof(char**) * ac);
	i = 1;
	y = 0;
	if (t->flags)
		i++;
	while (ac > i)
	{
		args[y] = ft_strsplit(av[i], ' ');
		y++;
		i++;
	}
	args[y] = NULL;
	return (args);
}

int		size_of(char ***args)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	y = 0;
	size = 0;
	while (args[x])
	{
		y = 0;
		while (args[x][y++])
			size++;
		x++;
	}
	return (size);
}

int		check_int(int a, char *s)
{
	char *s1;

	s1 = ft_itoa(a);
	if (s[0] == '+')
	{
		s1 = ft_strjoin_f("+", s1, 2);
		if (ft_strcmp(s, s1))
		{
			free(s1);
			ft_error(2);
		}
	}
	if (ft_strcmp(s, s1))
	{
		free(s1);
		ft_error(2);
	}
	return ((int)a);
}

int		size_of_tab(int ac, char **av, t_tab *t)
{
	char	***args;
	int		size;

	args = split_args(ac, av, t);
	size = size_of(args);
	cube_array_free(args);
	return (size);
}

int		*parse_args(int ac, char **av, t_tab *t)
{
	int		x;
	int		y;
	int		size;
	int		*square;
	char	***args;

	x = 0;
	check_arg(ac, av, t);
	args = split_args(ac, av, t);
	size = size_of(args);
	square = (int*)malloc(sizeof(int) * size);
	size = 0;
	while (args[x])
	{
		y = 0;
		while (args[x][y])
		{
			square[size++] = check_int(ft_atoi(args[x][y]), args[x][y]);
			y++;
		}
		x++;
	}
	cube_array_free(args);
	return (square);
}
