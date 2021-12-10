/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:43:09 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/10 11:44:12 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *x, char c)
{
	int	buffer;

	if (x->len < 2)
		return ;
	buffer = x->stack[0];
	x->stack[0] = x->stack[1];
	x->stack[1] = buffer;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	push(t_stack *x, t_stack *y, char c)
{
	int	i;

	if (y->len == 0)
		return ;
	x->len++;
	i = -1;
	while (++i < x->len)
		x->stack[x->len - i - 1] = x->stack[x->len - i - 2];
	x->stack[0] = y->stack[0];
	i = -1;
	while (++i < y->len)
		y->stack[i] = y->stack[i + 1];
	y->len--;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

void 	rotate(t_stack *x, char c)
{
	int	i;
	int	buffer;

	if (x->len < 2)
		return ;
	buffer = x->stack[0];
	i = -1;
	while (++i < x->len)
		x->stack[i] = x->stack[i + 1];
	x->stack[x->len - 1] = buffer;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	reverse(t_stack *x, char c)
{
	int	i;
	int	buffer;

	if (x->len < 2)
		return ;
	buffer = x->stack[x->len - 1];
	i = -1;
	while (++i < x->len)
		x->stack[x->len - i - 1] = x->stack[x->len - i - 2];
	x->stack[0] = buffer;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}
