/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:59:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/07 13:50:52 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_swap(int argc, char **argv)
{
	t_stack	a;
	//t_stack	b;

	a.len = argc;

	if (process_args(a, argv))
		return ; // error()
	
}

int	process_args(t_stack a, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(*argv[i] >= '0' || *argv[i] <= '9'|| *argv[i] == '-'))
			return (1);
		a.stack[i] = ft_atoi(argv[i]);
		i++;
	}
	printf("a.stack[%i] = %i\n", i, a.stack[i]);
	 return (0);
}

int main(int argc, char **argv) 
{
	push_swap(argc, argv);
	return (0);
}
