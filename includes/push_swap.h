/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:15:00 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/07 16:57:15 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	len;
	int *stack;
} t_stack;

void	push_swap(int argc, char **argv);
int		process_args(int argc, char **argv);
int		is_nbr(int argc, char **argv);
int		is_int(int argc, char **argv);
//int		is_unique(int argc, char **argv);

#endif
