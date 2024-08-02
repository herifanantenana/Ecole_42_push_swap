/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:56:24 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:45:25 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ps_reverse_rotate(t_stack **node)
{
	t_stack	*head;
	t_stack	*last;

	if (!(*node) || !(*node)->next)
		return (FALSE);
	head = *node;
	last = last_node(node);
	*node = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
	return (TRUE);
}

void	rra(t_stack **stack_a)
{
	if (ps_reverse_rotate(stack_a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	if (ps_reverse_rotate(stack_b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	reversed;

	reversed = FALSE;
	if (ps_reverse_rotate(stack_a))
		reversed = TRUE;
	if (ps_reverse_rotate(stack_b))
		reversed = TRUE;
	if (reversed)
		write(1, "rrr\n", 4);
}
