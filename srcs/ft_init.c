/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:46:30 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:57:30 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_a(t_stack **stack, char **argv, int free_argv)
{
	long	nbr;
	int		i;

	if (free_argv)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_exit(stack, argv, free_argv);
		nbr = ft_atol(argv[i]);
		if (range_error(nbr))
			error_exit(stack, argv, free_argv);
		if (duplicate_error(stack, (int)nbr))
			error_exit(stack, argv, free_argv);
		add_stack(stack, (int)nbr);
		i++;
	}
	if (free_argv)
		ft_free_tab_str(argv);
}
