/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 01:07:26 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:42:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_target_b(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		max_closer;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		max_closer = INT_MAX;
		while (tmp_a)
		{
			if (tmp_a->val > tmp_b->val && tmp_a->val < max_closer)
			{
				max_closer = tmp_a->val;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (max_closer == INT_MAX)
			tmp_b->target = min_node(*a);
		else
			tmp_b->target = target;
		tmp_b = tmp_b->next;
	}
}

void	init_stack_b(t_stack **a, t_stack **b)
{
	set_curr_index(a);
	set_curr_index(b);
	set_target_b(a, b);
}
