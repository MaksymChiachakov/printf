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

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static void	ft_putnstr(const char *s, int n)
{
	int	i;

	i = 0;
	while (s && s[i] && i < n)
		write(1, &s[i++], 1);
}

int	ft_print_str(const char *format, int *i, va_list args)
{
	char	*str;
	int		width, prec, left;
	int		len, printed, j;

	str = va_arg(args, char *);
	width = 0;
	prec = -1;
	left = 0;
	printed = 0;
	j = *i;
	if (!str)
		str = "(null)";

	while (format[j] == '-' || format[j] == '0')
	{
		if (format[j] == '-')
			left = 1;
		j++;
	}

	while (format[j] >= '0' && format[j] <= '9')
		width = width * 10 + (format[j++] - '0');

	if (format[j] == '.')
	{
		prec = 0;
		j++;
		while (format[j] >= '0' && format[j] <= '9')
			prec = prec * 10 + (format[j++] - '0');
	}

	while (format[j] && format[j] != 's')
		j++;
	*i = j; 

	len = ft_strlen(str);
	if (prec >= 0 && prec < len)
		len = prec;

	if (!left)
		while (width-- > len)
			printed += write(1, " ", 1);

	ft_putnstr(str, len);
	printed += len;

	if (left)
		while (width-- > len)
			printed += write(1, " ", 1);

	return (printed);
}
