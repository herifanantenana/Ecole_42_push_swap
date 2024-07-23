/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:54:09 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:29:48 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_rotate(t_stack **node)
{
	t_stack	*head;
	t_stack	*last;

	if (!(*node) || !(*node)->next)
		return (FALSE);
	head = *node;
	last = last_node(node);
	*node = head->next;
	(*node)->prev = NULL;
	head->next = NULL;
	last->next = head;
	head->prev = last;
	return (TRUE);
}

void	ra(t_stack **stack_a)
{
	if (ft_rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	if (ft_rotate(stack_b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	rotated;

	rotated = FALSE;
	if (ft_rotate(stack_a))
		rotated = TRUE;
	if (ft_rotate(stack_b))
		rotated = TRUE;
	if (rotated)
		write(1, "rr\n", 3);
}
