/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:39:08 by jlu               #+#    #+#             */
/*   Updated: 2024/02/20 21:34:50 by jlu              ###   ########.fr       */
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
		ft_putendl_fd("Memory Allocation failed, big sad!", 1);
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
	while (argv[i] != (void *)0)
	{
		n = ft_atol(argv[i]);
		//printf("init stack: %ld\n", n);
		if (n > INT_MAX || n < INT_MIN)
			error_msg_params("It may be too big or too small", a);
		if (check_dup(*a, (int)n) == 1)
			error_msg_params("how dare you put the same number twice!", a);
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
		error_msg_params("nothing to sort", &a);
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv);
	}
	else
		init_stack_a(&a, argv + 1);
	int i;
	i = 1;
	while (argv[i] != (void *)0)
	{
		printf("split: %s\n", argv[i]);
		i++;
	}
	if (stack_sorted(a) != 1)
	{
		if (stack_len(a) == 2)
			swap(&a);
		else if (stack_len(a) == 3)
			three_sort(&a);
		else
			sort_stacks(&a, &b);		
	}
	while (a->next)
	{
		printf("First: %i\n", a->value);
		a = a->next;
	}
	printf("First: %i\n", a->value);
	while (b->next)
	 {
	 	printf("Stack B: %i\n", b->value);
	 	b = b->next;
	 }
	 printf("stack B: %i\n", b->value);
	return (0);
}

// printf check
	//while (a->next)
	//{
	//	printf("First: %i\n", a->value);
	//	a = a->next;
	//}
	// b = a;
	// while (b->next)
	// {
	// 	printf("Stack: %i\n", b->value);
	// 	b = b->next;
	// }
	// printf("stack: %i\n", b->value);
	//int i;
	//i = 1;
	//while (argv[i] != (void *)0)
	//{
	//	printf("split: %s\n", argv[i]);
	//	i++;
	//}