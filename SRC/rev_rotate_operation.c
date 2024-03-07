/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:07:26 by jlu               #+#    #+#             */
/*   Updated: 2024/03/07 15:58:22 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
rra (reverse rotate a): Bottom number in A goes to the top of A
rrb (reverse rotate b): Bottom number in B goes to the top of B
rrr (rra + rrb)
*/
void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a, bool checker)
{
	rev_rotate(a);
	if (!checker)
		ft_putstr_fd("rra\n", 1);	
}

void	rrb(t_stack **b, bool checker)
{
	rev_rotate(b);
	if (!checker)
		ft_putstr_fd("rrb\n", 1);	
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!checker)
		ft_putstr_fd("rrr\n", 1);	
}