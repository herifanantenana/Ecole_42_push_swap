/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:10 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:19:19 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_3(t_stack **a)
{
	t_stack	*max;

	max = max_node(*a);
	if (max == *a)
		ra(a);
	else if (max == (*a)->next)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

static void	short_sort(t_stack **a, int len_a)
{
	if (len_a == 2)
		sa(a);
	else if (len_a == 3)
		sort_3(a);
}

static void	big_sort(t_stack **a, t_stack **b, int len_a)
{
	if (len_a-- > 3 && !is_stack_sorted(a))
		pb(a, b);
	if (len_a-- > 3 && !is_stack_sorted(a))
		pb(a, b);
	init_stack_a(a, b);
	while (len_a-- > 3 && !is_stack_sorted(a))
	{
		init_stack_a(a, b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_stack_b(a, b);
		move_b_to_a(a, b);
	}
	move_min_to_top(a, 'a');
}

void	init_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	(void)b;
	if (!a || !*a)
		return ;
	len_a = stack_len(*a);
	if (!is_stack_sorted(a))
	{
		if (len_a < 4)
			short_sort(a, len_a);
		else
			big_sort(a, b, len_a);
	}
}
