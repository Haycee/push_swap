/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <agirardi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:15:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/13 05:27:11 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> // !

typedef struct s_stack
{
	int	len;
	int *stack;
} t_stack;

/* push_swap.c */

void	push_swap(t_stack *a, t_stack *b);
void	stack_init(t_stack *a, t_stack *b, int argc, char **argv);
void	empty_a(t_stack *a, t_stack *b, int chunk_size);

/* swap.c */

void	swap_three(t_stack *a);
void	swap_five(t_stack *a, t_stack *b);
void	swap_hundred(t_stack *a, t_stack *b);

/* push_swap_utils.c */

int		is_sorted(t_stack *x);
int		find_lowest(t_stack *x);
int		find_largest(t_stack *x);
void	bubble_sort(int *array, int len);
void	value_to_index(t_stack *a);
void	print_tab(t_stack a, t_stack b, int to_print); // !

/* operations.c */

void	swap(t_stack *x, char c);
void	push(t_stack *x, t_stack *y, char c);
void 	rotate(t_stack *x, char c);
void 	reverse(t_stack *x, char c);

/* parse_args.c */

int		is_nbr(int argc, char **argv);
// int		is_int(int argc, char **argv);
int		is_unique(int argc, char **argv);
int		process_args(int argc, char **argv);

#endif
