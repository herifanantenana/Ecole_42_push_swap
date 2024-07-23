/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:03:05 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:57:05 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	syntax_error(char *nbr)
{
	int	len;
	int	i;

	len = ft_strlen(nbr);
	i = 0;
	if (len == 0)
		return (TRUE);
	while (ft_isspace(nbr[i]))
		i++;
	if (ft_issign(nbr[i]))
		i++;
	while (ft_isdigit(nbr[i]))
		i++;
	if (i != len)
	{
		return (TRUE);
	}
	return (FALSE);
}

int	range_error(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		return (TRUE);
	}
	return (FALSE);
}

int	duplicate_error(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		return (FALSE);
	while (tmp)
	{
		if (tmp->val == nbr)
		{
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

void	error_exit(t_stack **stack, char **str, int free_str)
{
	ft_printf("\033[0;31mError\033[0m\n");
	ft_free_stack(stack);
	if (free_str)
		ft_free_tab_str(str);
	exit(EXIT_FAILURE);
}
