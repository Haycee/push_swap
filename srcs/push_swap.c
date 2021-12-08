/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:59:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/08 17:30:46 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_swap(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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

	// print_tab(a, b, 'a');
	reverse(&a, 'x');
	swap(&a, 'a');
	rotate(&a, 'a');
	rotate(&a, 'a');
	rotate(&a, 'a');
	rotate(&a, 'a');
	rotate(&a, 'a');
	push(&b, &a, 'a');
	push(&a, &b, 'b');
	// print_tab(a, b, 'a');

	return (0);
}
