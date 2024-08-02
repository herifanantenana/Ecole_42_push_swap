/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:54:39 by arakotom          #+#    #+#             */
/*   Updated: 2024/08/03 00:44:55 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_stack_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	stack_len(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	add_stack(t_stack **stack, int nbr)
{
	t_stack	*new;
	t_stack	*last;

	new = new_node(nbr);
	if (!new)
		error_exit(stack, NULL);
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = last_node(stack);
	last->next = new;
	new->prev = last;
}

void	set_curr_index(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*curr;
	int		len;
	int		i;

	if (!stack || !*stack)
		return ;
	len = stack_len(*stack);
	curr = *stack;
	prev = NULL;
	i = 0;
	while (curr)
	{
		curr->index = i;
		curr->prev = prev;
		if (i <= len / 2)
			curr->above_med = TRUE;
		else
			curr->above_med = FALSE;
		i++;
		prev = curr;
		curr = curr->next;
	}
}

void	print_stack(t_stack **stack, char name, int free_stack)
{
	t_stack	*tmp;

	tmp = *stack;
	ft_printf("Stack %c : \n", name);
	while (tmp)
	{
		ft_printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
	if (free_stack)
		ps_free_stack(stack);
}
