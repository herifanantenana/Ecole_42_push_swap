/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 01:14:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:42:54 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_min_to_top(t_stack **stack, char name)
{
	t_stack	*min;

	min = min_node(*stack);
	move_to_top(stack, name, min);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node_to_move;

	node_to_move = (*b)->target;
	move_to_top(a, 'a', node_to_move);
	pa(b, a);
}
