/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:39:08 by jlu               #+#    #+#             */
/*   Updated: 2024/02/08 17:45:20 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argu(char *argv) // check input argu
{

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
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
		// checking if it's an int
	// else
	// check if all the argv are int
	// check_argu(argv[i]);
	return (0);
}