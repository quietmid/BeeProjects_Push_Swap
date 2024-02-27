/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:41:20 by jlu               #+#    #+#             */
/*   Updated: 2024/02/27 15:51:34 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* three nodes sort
	-if the 1st node is the biggest, rotate (1st to bottom)
	-if the 2nd node is the biggest, rev rotate (put the bottom to the top, so the biggest (2nd) to the bottom)
	-now that the biggest is at the bottom, check 1st and 2nd node, swap if needed
*/

void	three_sort(t_stack **stack)
{
	t_stack *big_node;

		big_node = find_max(*stack);
		if (*stack == big_node)
			ra(stack, false);
		else if ((*stack)->next == big_node)
			rra(stack, false);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack, false);
		//printf("three sorted\n");
}
