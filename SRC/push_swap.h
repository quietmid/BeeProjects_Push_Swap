/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:33:30 by jlu               #+#    #+#             */
/*   Updated: 2024/02/17 12:24:23 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h" 

#include <stdbool.h>
#include <limits.h>
// need to delete before
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

// Error Handling
int		check_dup(t_stack *a, int n);
void 	free_stack(t_stack **stack);
void 	free_errors(t_stack **a);
void	error_msg_params(char *msg, t_stack **a);

// Stack initiation
void	swap(t_stack **head);
int		stack_sorted(t_stack *stack);
// Utils
t_stack	*find_last(t_stack *stack);
int		stack_len(t_stack *stack);

// Commands Operation
void	rev_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **head);
void	push(t_stack **a, t_stack **b);
// Algorithms
void	three_sort(t_stack **stack);


#endif
