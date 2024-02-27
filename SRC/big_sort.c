/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:32:08 by jlu               #+#    #+#             */
/*   Updated: 2024/02/27 15:56:23 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_med && cheapest->target_node->above_med)
		mv_rotate_both(a, b, cheapest);
	else if (!(cheapest->above_med) && !(cheapest->target_node->above_med))
		mv_rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(a, b, false);
}

/*
	this find the node with the cheapest push_cost and set cheapest to true
*/
void	set_cheapest(t_stack *stack)
{
	long	cheap;
	t_stack	*cheap_node;
	 
	if (!stack)
		return ;
	cheap = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheap)
		{
			cheap = stack->push_cost;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheapest = true;
}

/*
	finding the cost to move a to b
*/
void	find_cost(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_med == false)
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_med == true)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

/*
	find a stack's target node in stack b. the target node for a is the closest smaller number to the 'a' node. if no closest smaller number is found, then the target node is the MAX nbr
*/
void	set_target_a(t_stack *a, t_stack *b) 
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index; //finding the closest smaller number so we start will long_min

	while (a) //loop through each b-node with each a-node to find the target_a
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match_index) 
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

/*
	current_index sets the current index value of each node and set their above_med value to true or false
*/
void	current_index(t_stack *stack)
{
	int i;
	int median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		++i;
	}
}
/* prep the nodes in stack A to find its target node in B and find out the cost and the cheapest node for pushing*/
void	prep_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	find_cost(a, b);
	set_cheapest(a);
	//printf("prep the nodes\n");
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		prep_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	three_sort(a);
	while (*b)
	{
		prep_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	move_min_top(a);
}