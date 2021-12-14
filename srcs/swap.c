/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:14:45 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/14 10:46:37 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_three(t_stack *a)
{
	int	i_largest;

	if (a->len == 3)
	{
		i_largest = is_largest(a);
		if (i_largest == 0)
			rotate(a, 'a');
		else if (i_largest == 1)
			reverse(a, 'a');
	}
	if (a->stack[0] > a->stack[1])
		swap(a, 'a');
}

void	swap_five(t_stack *a, t_stack *b)
{
	if (is_lowest(a) == 1)
		swap(a, 'a');
	while (a->len != 3)
	{
		while (is_lowest(a) != 0)
			reverse(a, 'a');
		push(b, a, 'b');
	}
	swap_three(a);
	push(a, b, 'a');
	push(a, b, 'a');
}

void	swap_large(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	j;

	if (!value_to_index(a))
	{
		error_handler(a, b);
		return ;
	}
	empty_a(a, b, chunk_size);
	i = -1;
	while (b->len != 0)
	{
		if (is_largest(b) == ++i)
		{
			j = -1;
			if (i < b->len / 2)
				while (++j != i)
					rotate(b, 'b');
			if (i >= b->len / 2)
				while (++j + i != b->len)
					reverse(b, 'b');
			push(a, b, 'a');
			i = -1;
		}
	}
}
