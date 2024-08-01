/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/17 14:46:30 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 20:57:30 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ps_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ps_join_arg(char **argv)
{
	char	*result;
	int		i;

	i = 1;
	result = ft_strdup("");
	while (argv[i])
	{
		result = ps_strjoin(result, argv[i]);
		if (!argv[i] || !argv[i][0])
		{
			ft_putstr_fd("Error", 2);
			free(result);
			exit(1);
		}
		result = ps_strjoin(result, " ");
		i++;
	}
	return (result);
}

void	init_a(t_stack **stack, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_exit(stack, argv);
		nbr = ft_atol(argv[i]);
		if (range_error(nbr))
			error_exit(stack, argv);
		if (duplicate_error(stack, (int)nbr))
			error_exit(stack, argv);
		add_stack(stack, (int)nbr);
		i++;
	}
	ft_free_tab_str(argv);
}
