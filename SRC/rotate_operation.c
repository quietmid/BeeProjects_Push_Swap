/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:04:49 by jlu               #+#    #+#             */
/*   Updated: 2024/02/22 13:18:30 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
ra (rotate a): Top number in A goes to the bottom of A
rb (rotate b): Top number in B goes to the bottom of B
rr (ra + rb)
*/

void	rotate(t_stack **stack)
{
	t_stack *last_node;

	if(!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		ft_putstr_fd("ra\n", 1);	
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_putstr_fd("rb\n", 1);	
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		ft_putstr_fd("rr\n", 1);	
}