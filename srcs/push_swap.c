/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:59:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/14 11:00:30 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->len <= 1 || is_sorted(a))
		return ;
	if (a->len <= 3)
		swap_three(a);
	if (a->len > 3 && a->len <= 5)
		swap_five(a, b);
	if (a->len > 5 && a->len <= 100)
		swap_large(a, b, 20);
	if (a->len > 100)
		swap_large(a, b, 40);
}

void	empty_a(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	j;
	int	chunk;

	chunk = chunk_size;
	while (a->len != 0)
	{
		i = -1;
		while (++i < a->len)
		{
			if (a->stack[i] < chunk)
			{
				j = -1;
				if (i < a->len / 2)
					while (++j != i)
						rotate(a, 'a');
				if (i >= a->len / 2)
					while (++j + i != a->len)
						reverse(a, 'a');
				push(b, a, 'b');
				i = -1;
			}
		}
		chunk += chunk_size;
	}
}

int	stack_init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	b->len = 0;
	a->len = argc - 1;
	a->stack = malloc(sizeof(int) * a->len);
	b->stack = malloc(sizeof(int) * a->len);
	if (!a || !b)
		return (0);
	i = 0;
	while (++i != argc)
		a->stack[i - 1] = ft_atoi(argv[i]);
	return (1);
}

void	error_handler(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	ft_putstr_fd("Error\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1 || process_args(argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (!stack_init(&a, &b, argc, argv))
	{
		error_handler(&a, &b);
		return (0);
	}
	push_swap(&a, &b);
	return (0);
}
