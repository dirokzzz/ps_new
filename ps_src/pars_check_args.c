#include "checker.h"

char	***split_args(int ac, char **av)
{
	int		i;
	char	***args;
	int		y;

	args = (char***)malloc(sizeof(char**) * ac);
	i = 1;
	y = 0;
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

int		*parse_args(int ac, char **av)
{
	int		x;
	int		y;
	int		size;
	int		*square;
	char	***args;

	x = 0;
	args = split_args(ac, av);
	size = size_of(args);
	square = (int*)malloc(sizeof(int) * size);
	size = 0;
	while (args[x])
	{
		y = 0;
		while (args[x][y])
		{
			square[size] = (int)ft_atoi(args[x][y++]);
			size++;
		}
		x++;
	}
	cube_array_free(args);
	return (square);
}

int		size_of_tab(int ac, char **av)
{
	char	***args;
	int		size;

	args = split_args(ac, av);
	size = size_of(args);
	cube_array_free(args);
	return (size);
}

void	sort_int_tab(int *tab, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			ft_swap_int(&tab[i], &tab[i - 1]);
			i = 0;
		}
		i++;
	}
}
