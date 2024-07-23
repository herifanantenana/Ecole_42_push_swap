/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:28:13 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:37:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		free_argv;

	stack_a = NULL;
	stack_b = NULL;
	free_argv = FALSE;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = (const char **)ft_split((char *)argv[1], ' ');
		free_argv = TRUE;
	}
	if (argv)
	{
		init_a(&stack_a, (char **)argv, free_argv);
		init_sort(&stack_a, &stack_b);
		ft_free_stack(&stack_a);
	}
	return (0);
}
