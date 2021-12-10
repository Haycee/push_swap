/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:01:45 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/10 15:35:01 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_largest(t_stack *x)
{
	int	i_largest;
	int i;

	i_largest = 0;
	i = -1;
	while (++i != x->len)
		if (x->stack[i] > x->stack[i_largest])
			i_largest = i;
	return (i_largest);
}

int	find_lowest(t_stack *x)
{
	int	i_lowest;
	int i;

	i_lowest = 0;
	i = -1;
	while (++i != x->len)
		if (x->stack[i] < x->stack[i_lowest])
			i_lowest = i;
	return (i_lowest);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i != a->len - 1)
	{
		printf("\n");
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_tab(t_stack a, t_stack b, int to_print)
{
	int	i;

	if (to_print == 'a')
	{
		i = 0;
		printf("=====Tab A=====\n");
		while (i < a.len)
		{
			printf("%d\n", a.stack[i]);
			i++;
		}
		printf("===============\n");
	}
	else if (to_print == 'b')
	{
		i = 0;
		printf("=====Tab B=====\n");
		while (i < b.len)
		{
			printf("%d\n", b.stack[i]);
			i++;
		}
		printf("===============\n");
	}
}
