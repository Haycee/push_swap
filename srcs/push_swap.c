/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <agirardi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:59:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/10 19:27:05 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->len < 2)
		return	;
	if (a->len < 4)
		swap_three(a);
	if (a->len < 6)
		swap_five(a, b);

	//./push_swap 1 2 3 4
	// pb pa
}

// void	swap_hundred(t_stack *a, t_stack *b)
// {

// }

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

void	swap_three(t_stack *x)
{
	int	i_largest;

	if (x->len == 3)
	{
		i_largest = find_largest(x);
		if (i_largest ==  0)
			rotate(x, 'a');
		else if (i_largest ==  1)
			reverse(x, 'a');
	}
	if (x->stack[0] > x->stack[1])
		swap(x, 'a');
}

void	stack_init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 0;
	b->len = 0;
	a->len = argc - 1;
	a->stack = malloc(sizeof(int) * a->len);
	b->stack = malloc(sizeof(int) * a->len);
	while (++i != argc)
		a->stack[i - 1] = ft_atoi(argv[i]);
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2 || process_args(argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	stack_init(&a, &b, argc, argv);
	push_swap(&a, &b);
	print_tab(a, b, 'a');
	return (0);
}
