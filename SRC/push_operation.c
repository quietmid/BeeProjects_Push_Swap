/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:49:12 by jlu               #+#    #+#             */
/*   Updated: 2024/02/23 14:45:31 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a): Top number in B goes to the top of A
pb (push b): Top number in A goes to the top of B
*/
void	push(t_stack **src, t_stack **dest)
{
	t_stack *temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (!*dest)
	{
		*dest = temp;
		(*dest)->next = NULL;
	}
	else
	{
		temp->next = *dest;
		*dest = temp;
	}
	(*src)->prev = NULL;
}

void	pb(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_putstr_fd("pb\n", 1);	
}

void	pa(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		ft_putstr_fd("pa\n", 1);	
}