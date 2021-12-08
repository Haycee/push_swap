/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:15:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/08 17:30:44 by agirardi         ###   ########lyon.fr   */
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

void	push_swap(int argc, char **argv);
void	stack_init(t_stack *a, t_stack *b, int argc, char **argv);

/* push_swap_utils.c */

void	swap(t_stack *x, char c);
void	push(t_stack *x, t_stack *y, char c);
void 	rotate(t_stack *x, char c);
void 	reverse(t_stack *x, char c);
void	print_tab(t_stack a, t_stack b, int to_print); // !

/* check_args.c */

int		process_args(int argc, char **argv);
int		is_nbr(int argc, char **argv);
int		is_int(int argc, char **argv);
int		is_unique(int argc, char **argv);

#endif
