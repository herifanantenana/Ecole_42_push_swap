/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:58:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:42:45 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_set_min_cost_a(t_stack **tmp_a, int len_a, int len_b,
		int is_above)
{
	if (is_above)
	{
		if ((*tmp_a)->index > (*tmp_a)->target->index)
			(*tmp_a)->push_cost = (*tmp_a)->index;
		else
			(*tmp_a)->push_cost = (*tmp_a)->target->index;
	}
	else
	{
		if ((len_a - (*tmp_a)->index) > (len_b - (*tmp_a)->target->index))
			(*tmp_a)->push_cost = len_a - (*tmp_a)->index;
		else
			(*tmp_a)->push_cost = len_b - (*tmp_a)->target->index;
	}
}

static void	set_target_a(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		min_closer;

	tmp_a = *a;
	while (tmp_a)
	{
		tmp_b = *b;
		min_closer = INT_MIN;
		while (tmp_b)
		{
			if (tmp_b->val < tmp_a->val && tmp_b->val > min_closer)
			{
				min_closer = tmp_b->val;
				target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (min_closer == INT_MIN)
			tmp_a->target = max_node(*b);
		else
			tmp_a->target = target;
		tmp_a = tmp_a->next;
	}
}

static void	set_push_cost_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	int		len_a;
	int		len_b;

	tmp_a = *a;
	len_a = stack_len(*a);
	len_b = stack_len(*b);
	while (tmp_a)
	{
		tmp_a->push_cost = tmp_a->index;
		if ((tmp_a->above_med) && (tmp_a->target->above_med))
			ft_set_min_cost_a(&tmp_a, len_a, len_b, TRUE);
		else if (!(tmp_a->above_med) && !(tmp_a->target->above_med))
			ft_set_min_cost_a(&tmp_a, len_a, len_b, FALSE);
		else
		{
			if (!(tmp_a->above_med))
				tmp_a->push_cost = len_a - tmp_a->index;
			if (tmp_a->target->above_med)
				tmp_a->push_cost += tmp_a->target->index;
			else
				tmp_a->push_cost += len_b - tmp_a->target->index;
		}
		tmp_a = tmp_a->next;
	}
}

static void	set_best_node(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*best_node;
	int		min_cost;

	tmp = *a;
	min_cost = INT_MAX;
	while (tmp)
	{
		tmp->best_node = FALSE;
		if (tmp->push_cost < min_cost)
		{
			min_cost = tmp->push_cost;
			best_node = tmp;
		}
		tmp = tmp->next;
	}
	best_node->best_node = TRUE;
}

void	init_stack_a(t_stack **a, t_stack **b)
{
	set_curr_index(a);
	set_curr_index(b);
	set_target_a(a, b);
	set_push_cost_a(a, b);
	set_best_node(a);
}
