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

typedef struct s_list
{
	int				values;
	int				index;
	struct s_list	*next;
	struct s_list	*prev; //not sure if we need this yet
}		t_list;

#endif
