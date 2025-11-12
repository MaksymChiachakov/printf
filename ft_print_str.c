/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:20:17 by mchiacha          #+#    #+#             */
/*   Updated: 2025/11/08 18:04:24 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static int	str_len(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

static void	put_nstr(const char *s, int n)
{
	while (n-- > 0 && *s)
		write(1, s++, 1);
}

int	ft_print_str(const char *format, int *i, va_list args)
{
	char	*s;
	int		len;

	(void)format;
	(void)i;
	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	len = str_len(s);
	put_nstr(s, len);
	return (len);
}
