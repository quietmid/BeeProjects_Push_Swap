/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:33:30 by jlu               #+#    #+#             */
/*   Updated: 2024/02/12 18:22:33 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h" 

#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev; //not sure if we need this yet
}		t_stack;

// Error Handling
int		check_dup(t_stack *a, int n);
void 	free_stack(t_stack **stack);
void 	free_errors(t_stack **a);
void	error_msg_params(char *msg);

// Stack initiation

// Utils
t_stack	*find_last(t_stack *stack);
// Commands Operation

// Algorithms



#endif
