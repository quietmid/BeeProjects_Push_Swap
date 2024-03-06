/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:34 by jlu               #+#    #+#             */
/*   Updated: 2024/03/06 15:02:28 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//void	move_min_top(t_stack **a)
//{
//	while ((*a)->value != find_min(*a)->value)
//	{
//		if (find_min(*a)->above_med == true)
//			rotate(a);
//		else
//			rev_rotate(a);
//	}
//}

void	move_min_top(t_stack **a)
{
	t_stack *min_node;

	min_node = find_min(*a);
	//printf("min_node above med: %d\n", min_node->above_med);
	if (min_node->above_med)
		while (*a != min_node)
			ra(a, false);
	else
		while (*a != min_node)
			rra(a, false);
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

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}