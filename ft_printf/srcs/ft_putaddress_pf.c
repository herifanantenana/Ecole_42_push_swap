/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:05:47 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 02:00:42 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putaddress_pf(int *count, void *p)
{
	if (!p)
		ft_putstr_pf(count, "(nil)");
	else
	{
		ft_putstr_pf(count, "0x");
		if (p == (void *)-1)
			ft_putstr_pf(count, "ffffffffffffffff");
		else
			ft_putnbr_base_pf(count, (size_t)p, BASE_HEX_LOW);
	}
}
