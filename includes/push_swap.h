/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:15:00 by agirardi          #+#    #+#             */
/*   Updated: 2022/04/23 01:56:16 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int	len;
	int	*stack;
}	t_stack;

/* push_swap.c */

void	push_swap(t_stack *a, t_stack *b);
void	empty_a(t_stack *a, t_stack *b, int chunk_size);
void	error_handler(t_stack *a, t_stack *b);
int		stack_init(t_stack *a, t_stack *b, int argc, char **argv);

/* swap.c */

void	swap_three(t_stack *a);
void	swap_five(t_stack *a, t_stack *b);
void	swap_large(t_stack *a, t_stack *b, int chunck_size);

/* push_swap_utils.c */

int		is_sorted(t_stack *x);
int		is_lowest(t_stack *x);
int		is_largest(t_stack *x);
int		value_to_index(t_stack *a, int i);

/* operations.c */

void	swap(t_stack *x, char c);
void	push(t_stack *x, t_stack *y, char c);
void	rotate(t_stack *x, char c);
void	reverse(t_stack *x, char c);

/* parse_args.c */

int		is_nbr(int argc, char **argv);
int		is_int(int argc, char **argv);
int		is_unique(int argc, char **argv);
int		process_args(int argc, char **argv);

#endif
