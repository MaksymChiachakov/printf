/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:22:00 by mchiacha          #+#    #+#             */
/*   Updated: 2025/11/08 18:03:28 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	nb;
	int		len;
	char	c;

	nb = n;
	len = 0;
	if (nb > 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 10)
		len += ft_print_nbr(nb / 10);
	c = nb % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}	
