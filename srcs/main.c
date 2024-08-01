/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/14 15:28:13 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:37:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*list_joined;
	char	**list_splitted;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		error_exit(NULL, NULL);
	list_joined = ps_join_arg((char **)argv);
	list_splitted = ft_split(list_joined, ' ');
	free(list_joined);
	if (!list_splitted || list_splitted[0] == NULL)
		error_exit(NULL, list_splitted);
	init_a(&stack_a, list_splitted);
	init_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
