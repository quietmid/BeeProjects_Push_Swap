/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:33:30 by jlu               #+#    #+#             */
/*   Updated: 2024/02/08 17:55:42 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h" 

#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
	int				values;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev; //not sure if we need this yet
}		t_stack;

#endif
