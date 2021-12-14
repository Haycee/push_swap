/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:01:45 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/14 14:16:24 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_largest(t_stack *x)
{
	int	i_largest;
	int	i;

	i_largest = 0;
	i = -1;
	while (++i != x->len)
		if (x->stack[i] > x->stack[i_largest])
			i_largest = i;
	return (i_largest);
}

int	is_lowest(t_stack *x)
{
	int	i_lowest;
	int	i;

	i_lowest = 0;
	i = -1;
	while (++i != x->len)
		if (x->stack[i] < x->stack[i_lowest])
			i_lowest = i;
	return (i_lowest);
}

int	is_sorted(t_stack *x)
{
	int	i;

	i = 0;
	while (i != x->len - 1)
	{
		if (x->stack[i] > x->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	bubble_sort(int *array, int len)
{
	int	buffer;
	int	check;
	int	i;

	check = 1;
	while (check != 0)
	{
		i = 0;
		check = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				buffer = array[i];
				array[i] = array[i + 1];
				array[i + 1] = buffer;
				check++;
			}
			i++;
		}
	}
}

int	value_to_index(t_stack *a, int i)
{
	int	*array;
	int	j;

	array = malloc(sizeof(int) * a->len - 1);
	if (!array)
		return (0);
	while (++i < a->len)
		array[i] = a->stack[i];
	bubble_sort(array, a->len);
	i = -1;
	while (++i < a->len)
	{
		j = -1;
		while (++j < a->len)
		{
			if (a->stack[i] == array[j])
			{
				a->stack[i] = j;
				break ;
			}
		}
	}
	free (array);
	return (1);
}
