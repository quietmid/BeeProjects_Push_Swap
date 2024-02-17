/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:16:57 by jlu               #+#    #+#             */
/*   Updated: 2024/02/17 12:17:11 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//target node for a -> b is the closest smaller number. if its not found, then the target node is th max value node

//target node for b -> a is the closest largest number, if its not found, then the target node is the min value node

// then based on where the smallest node is, we rotate or rev rotate