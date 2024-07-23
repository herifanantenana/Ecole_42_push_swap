/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:52:43 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:29:51 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_swap(t_stack **node)
{
	t_stack	*head;

	if (!(*node) || !(*node)->next)
		return (FALSE);
	head = (*node)->next;
	if (head->next)
		head->next->prev = *node;
	head->prev = NULL;
	(*node)->next = head->next;
	(*node)->prev = head;
	head->next = *node;
	*node = head;
	return (TRUE);
}

void	sa(t_stack **stack_a)
{
	if (ft_swap(stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	if (ft_swap(stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	swapped;

	swapped = FALSE;
	if (ft_swap(stack_a))
		swapped = TRUE;
	if (ft_swap(stack_b))
		swapped = TRUE;
	if (swapped)
		write(1, "ss\n", 3);
}
