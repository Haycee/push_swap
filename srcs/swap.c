/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <agirardi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:14:45 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/13 05:28:41 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_three(t_stack *a)
{
	int	i_largest;

	if (a->len == 3)
	{
		i_largest = find_largest(a);
		if (i_largest ==  0)
			rotate(a, 'a');
		else if (i_largest ==  1)
			reverse(a, 'a');
	}
	if (a->stack[0] > a->stack[1])
		swap(a, 'a');
}

void	swap_five(t_stack *a, t_stack *b)
{
	if (find_lowest(a) == 1)
		swap(a, 'a');
	while (a->len != 3)
	{
		while (find_lowest(a) != 0)
				reverse(a, 'a');
		push(b, a, 'b');
	}
	swap_three(a);
	push(a, b, 'a');
	push(a, b, 'a');
}

void	swap_hundred(t_stack *a, t_stack *b)
{
	value_to_index(a);
	empty_a(a, b, 20);
}
