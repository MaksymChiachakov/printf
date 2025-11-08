/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:34:20 by mchiacha          #+#    #+#             */
/*   Updated: 2025/11/08 18:04:09 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				len;
	char			c;
	char			*base;

	len = 0;
	base = "0123456789abcdef";
	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	len += write(1, "0x", 2);
	if (addr >= 16)
		len += ft_print_ptr((void *)(addr / 16));
	c = base[addr % 16];
	len += write(1, &c, 1);
	return (len);
}
