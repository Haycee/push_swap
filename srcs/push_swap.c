/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:59:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/07 16:58:03 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_swap(int argc, char **argv)
{
	// t_stack	a;
	//t_stack	b;

	(void)argc;
	(void)argv;
	
	//a.len = argc;

	//if (process_args(a, argc, argv))
	//	exit(1);
	
}

int	process_args(int argc, char **argv)
{
	printf("is_nbr	: %i\n", is_nbr(argc, argv));
	printf("is_int	: %i\n", is_int(argc, argv));
	return (0);
	//is_unique(argc, argv);
}

int main(int argc, char **argv) 
{
	int	check;

	check = 1;
	if (argc < 2 || process_args(argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	return (0);
}
