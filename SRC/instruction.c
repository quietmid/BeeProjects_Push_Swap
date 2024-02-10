/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:49:12 by jlu               #+#    #+#             */
/*   Updated: 2024/02/08 17:01:54 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
HELPER functions that we will be using in PushSwap
sa (swap a) swap the top two numbers in A
sb (swap b) swap the top two numbers in B
ss (sa + sb) 

ra (rotate a): Top number in A goes to the bottom of A
rb (rotate b): Top number in B goes to the bottom of B
rr (ra + rb)

rra (reverse rotate a): Bottom number in A goes to the top of A
rrb (reverse rotate b): Bottom number in B goes to the top of B
rrr (rra + rrb)

pa (push a): Top number in B goes to the top of A
pb (push b): Top number in A goes to the top of B
*/