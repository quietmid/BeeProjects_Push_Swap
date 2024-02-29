/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:32:08 by jlu               #+#    #+#             */
/*   Updated: 2024/02/29 19:21:26 by jlu              ###   ########.fr       */
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
	//printf("stack len: %i\n", stack_len(stack));
	median = (stack_len(stack) / 2);
	//printf("median: %i\n", median);
	while (stack)
	{
		stack->index = i;
		//printf("index: %i\n", i);
		if (i <= median)
			stack->above_med = true;
		else
			stack->above_med = false;
		//printf("above med: %d\n", stack->above_med);
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

static void	print_stacks(t_stack **a, char *stack)
{
		t_stack *temp;
		
		temp = *a;

		printf("stack %s:", stack);
		while ((temp != NULL && temp->next))
		{
			printf(" %i ", temp->value);
			temp = temp->next;
		}
		printf("\n");
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
	{
		pb(a, b, false);
		print_stacks(a, "A");
		print_stacks(b, "B");
	}
	if (len_a-- > 3 && !stack_sorted(*a))
	{
		pb(a, b, false);
		print_stacks(a, "A");
		print_stacks(b, "B");
	}
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		prep_nodes_a(*a, *b);
		move_a_to_b(a, b);
		print_stacks(a, "A");
		print_stacks(b, "B");
	}
	three_sort(a);
	while (*b)
	{
		prep_nodes_b(*a, *b);
		move_b_to_a(a, b);
		print_stacks(a, "A");
		print_stacks(b, "B");
	}
	current_index(*a);
	//printf("top node %i\n", (*a)->value);
	//printf("%i\n", find_min(*a)->value);
	move_min_top(a);
}
