/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:59:57 by jlu               #+#    #+#             */
/*   Updated: 2024/02/27 15:10:58 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sa (swap a) swap the top two numbers in A
sb (swap b) swap the top two numbers in B
ss (sa + sb) 
*/

void	swap(t_stack **head) // swap the top 2 nodes
{
	t_stack *temp;
	
	if (!*head || !(*head)->next) // adding the () making sure that it checks head->next instead of just the head
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool checker)
{
	swap(a);
	if (!checker)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_putstr_fd("ss\n", 1);
}