/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:33:30 by jlu               #+#    #+#             */
/*   Updated: 2024/02/27 14:29:33 by jlu              ###   ########.fr       */
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
	int				push_cost;
	bool			above_med;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

// Error Handling
int		check_dup(t_stack *a, int n);
void 	free_stack(t_stack **stack);
void 	free_errors(t_stack **a);
void	error_msg_params(char *msg, t_stack **a);

// Stack initiation
void	init_stack_a(t_stack **a, char **argv, int ac);
int		stack_sorted(t_stack *stack);
void	current_index(t_stack *stack);
void 	prep_nodes_a(t_stack *a, t_stack *b);
void	prep_nodes_b(t_stack *a, t_stack *b);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

// Utils
t_stack	*find_last(t_stack *stack);
int		stack_len(t_stack *stack);
void	move_min_top(t_stack **a);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	find_cost(t_stack *a, t_stack *b);
t_stack *get_cheapest(t_stack *stack);

// Commands Operation
void	swap(t_stack **head);
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);
void	rotate(t_stack **stack);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);
void	push(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a, bool checker);
void	pa(t_stack **a, t_stack **b, bool checker);
void	mv_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	mv_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// Algorithms
void	three_sort(t_stack **stack);
void	sort_stacks(t_stack **a, t_stack **b);

#endif
