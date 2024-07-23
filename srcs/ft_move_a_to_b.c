/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:21:20 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:21:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_both_ref_a(t_stack **a, t_stack **b, t_stack *top_node,
		int above_med)
{
	while (*a != top_node && *b != top_node->target)
	{
		if (above_med)
			rr(a, b);
		else
			rrr(a, b);
	}
	set_curr_index(a);
	set_curr_index(b);
}

void	move_to_top(t_stack **stack, char name, t_stack *top_node)
{
	set_curr_index(stack);
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_med)
				rb(stack);
			else
				rrb(stack);
		}
	}
	set_curr_index(stack);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node_to_move;

	node_to_move = best_node(*a);
	if (node_to_move)
	{
		if (node_to_move->above_med && node_to_move->target->above_med)
			move_both_ref_a(a, b, node_to_move, TRUE);
		else if (!(node_to_move->above_med)
			&& !(node_to_move->target->above_med))
			move_both_ref_a(a, b, node_to_move, FALSE);
		move_to_top(a, 'a', node_to_move);
		move_to_top(b, 'b', node_to_move->target);
		pb(a, b);
	}
}
