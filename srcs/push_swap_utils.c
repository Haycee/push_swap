/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:01:45 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/07 17:03:39 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			// printf("argv[%i][%i] : %c\n", i, j, argv[i][j]);
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')|| argv[i][j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	 return (0);
}

int	is_int(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i != argc)
	{
		printf("atoi : %i\n", ft_atoi(argv[i]));
		if (ft_strlen(argv[i]) > 11)
			return (1);
		if (ft_atoi(argv[i]) == -1)
		{
			if (argv[i][0] == '-' && ft_strlen(argv[i]) == 11)
				return (1);
			else if (ft_strlen(argv[i]) == 10)
				return (1);
		}
		i++;
	}
	return (0);
}
