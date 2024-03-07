/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:46 by jlu               #+#    #+#             */
/*   Updated: 2024/03/07 15:56:08 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack *temp;
	t_stack *current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->value = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_all(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}
// changed the output location 2 for standard error
void	error_msg_params(char *msg, t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2); 
	ft_putendl_fd(msg, 1);
	exit (1);
}

void	error_msg_params2(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 1);
	exit (1);
}