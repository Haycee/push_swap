/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <agirardi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:59:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/09 17:14:28 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->len < 2)
		return	;
	if (a->len < 4)
		swap_three(a, b);
}

void	swap_three(t_stack *a, t_stack *b)
{
	int	i_largest;
	int i;

	if (a->len < 3)
		if (a->stack[0] > a->stack[1])
		{
			swap(a, 'a');
			return ;
		}
		else
			return ;
	i_largest = 0;
	i = -1;
	while (++i != a->len)
		if (a->stack[i] > a->stack[i_largest])
			i_largest = i;
	if (i_largest ==  0)
		rotate(a, 'a');
	else if (i_largest ==  1)
		reverse(a, 'a');
	if (a->stack[0] > a->stack[1])
		swap(a, 'a');
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
	print_tab(a, b, 'a');
	push_swap(&a, &b);
	print_tab(a, b, 'a');
	return (0);
}
