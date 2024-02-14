/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:49:12 by jlu               #+#    #+#             */
/*   Updated: 2024/02/14 18:24:16 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
HELPER functions that we will be using in PushSwap
sa (swap a) swap the top two numbers in A
sb (swap b) swap the top two numbers in B
ss (sa + sb) 

ra (rotate a): Top number in A goes to the bottom of A
rb (rotate b): Top number in B goes to the bottom of B
rr (ra + rb)

rra (reverse rotate a): Bottom number in A goes to the top of A
rrb (reverse rotate b): Bottom number in B goes to the top of B
rrr (rra + rrb)

pa (push a): Top number in B goes to the top of A
pb (push b): Top number in A goes to the top of B
*/

#include "push_swap.h"
void	swap(t_stack **head) // swap the top 2 nodes
{
	t_stack *temp;
	
	if (!*head || !(*head)->next) // adding the () making sure that it checks head->next instead of just the head
		return ;
	temp = *head;
	//printf("temp head: %i\n", temp->value);
	*head = (*head)->next;
	//printf("head: %i\n", (*head)->value);
	temp->next = (*head)->next;
	//printf("temp next: %i\n", temp->next->value);
	//printf("head next: %i\n", (*head)->next->value);
	//(*head)->next->prev = *head;
	(*head)->next = temp;
	//printf("head next: %i\n", (*head)->next->value);
	(*head)->prev = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack *last_node;

	if(!*stack || !(*stack)->next)
		return ;
	//printf("stack head: %i\n", (*stack)->value);
	last_node = find_last(*stack);
	//printf("last node: %i\n", last_node->value);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	//printf("last node next: %i\n", last_node->next->value);
	//printf("last node: %i\n", last_node->value);
	//printf("sec node: %i\n", (*stack)->value);

	//printf("sec node: %i\n", last_node->next->prev->value);
	//last_node->next->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack *last_node;
	
	if(!*stack || !(*stack)->next)
		return ;
	//printf("stack head: %i\n", (*stack)->value);
	last_node = find_last(*stack);
	//printf("last node: %i\n", last_node->value);
	//printf("last node prev: %i\n", last_node->prev->value);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	//printf("new head: %i\n", (*stack)->value);
	*stack = last_node;
	//printf("head next: %i\n", (*stack)->next->value);
	last_node->next->prev = last_node;
}