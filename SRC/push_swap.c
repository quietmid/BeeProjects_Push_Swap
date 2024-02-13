/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:39:08 by jlu               #+#    #+#             */
/*   Updated: 2024/02/13 18:21:36 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s <= 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}


static void	stack_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;
	
	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		error_msg_params("Node Memory Allocation Failed, Sucka!");
	node->next = NULL;
	node->value = n;
	if (!(*stack)) //check if the stack is empty or currently pointing to Null, indicating first node needs to be found
	{
		*stack = node;
		node->prev = NULL; // set the head node's previous pointer to NULL as its the first node
	}
	else // if the stack is not empty then existing nodes are in the linked list
	{
		last_node = find_last(*stack); // find the last node which is the previous processed node
		last_node->next = node; //Append the new node the current value that's passed through
		node->prev = last_node; // update the new node's info on its prev node 
	}
	//printf("stack node: %i\n", node->value);
}

void init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		n = ft_atol(argv[i]);
		printf("init stack: %ld\n", n);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (check_dup(*a, (int)n) == 1)
			free_errors(a);
		stack_node(a, (int)(n));
		i++;
	}
}

#include "stdio.h"
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
	{	
		printf("no string"); // error check temp
		return (1);
	}
	// if the argc count is 2 then we split them in arrays of str
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	int i;
	i = 0;
	while (argv[i] != '\0')
	{
		printf("split: %s\n", argv[i]);
		i++;
	}
	// convert all array into long int and store them in stack a
	init_stack_a(&a, argv);
	//while (a->next)
	//{
	//	printf("First: %i\n", a->value);
	//	a = a->next;
	//}
	swap(&a);
	while (a->next)
	{
		printf("Swapped: %i\n", a->value);
		a = a->next;
	}
	printf("Swapped: %i\n", a->value);
	return (0);
}