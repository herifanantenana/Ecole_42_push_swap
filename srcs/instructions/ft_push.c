/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:50:58 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:29:38 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*head;

	if (!src || !(*src))
		return (FALSE);
	head = *src;
	*src = head->next;
	if (*src)
		(*src)->prev = NULL;
	head->next = *dst;
	if (*dst)
		(*dst)->prev = head;
	*dst = head;
	return (TRUE);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (ft_push(stack_b, stack_a))
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_a, stack_b))
		write(1, "pb\n", 3);
}
