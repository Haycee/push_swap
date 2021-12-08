#include "../includes/push_swap.h"

int	process_args(int argc, char **argv)
{
	// printf("is_nbr		: %i\n", is_nbr(argc, argv));
	// printf("is_int		: %i\n", is_int(argc, argv));
	// printf("is_unique	: %i\n", is_unique(argc, argv));
	if (!is_nbr(argc, argv) || !is_int(argc, argv) || !is_unique(argc, argv))
		return (1);
	return (0);
}

int is_nbr(int argc ,char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && ft_strlen(argv[i]) < 2)
				return (0);
			if (argv[i][j] == '-' && j != 0)
				return (0);
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	 return (1);
}

int	is_int(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i != argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (0);
		if (ft_atoi(argv[i]) == -1)
		{
			if (argv[i][0] == '-' && ft_strlen(argv[i]) == 11)
				return (0);
			else if (ft_strlen(argv[i]) == 10)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_unique(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i != argc)
	{
		j = i + 1;
		while (j != argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
