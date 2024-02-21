/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:49:12 by jlu               #+#    #+#             */
/*   Updated: 2024/02/21 17:42:46 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a): Top number in B goes to the top of A
pb (push b): Top number in A goes to the top of B
*/
void	push(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (!*b)
	{
		*b = temp;
		(*b)->next = NULL;
	}
	else
	{
		temp->next = *b;
		*b = temp;
	}
	(*a)->prev = NULL;
}

void	pa(t_stack **a, bool checker)
{
	push(a);
	if (!checker)
		ft_putstr_fd("pa\n", 1);	
}

void	pb(t_stack **b, bool checker)
{
	push(b);
	if (!checker)
		ft_putstr_fd("pb\n", 1);	
}