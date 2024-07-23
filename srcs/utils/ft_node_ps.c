/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:54:39 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 21:42:46 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*new_node(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = nbr;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*last_node(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	while (last->next)
		last = last->next;
	return (last);
}

t_stack	*max_node(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->val > max->val)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*min_node(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->val < min->val)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*best_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->best_node)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
