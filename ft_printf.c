/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:03:55 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/23 18:36:14 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char c)
{
	const char	*specifier;
	int			i;

	i = 0;
	specifier = "cspdiuxX%";
	while (specifier[i])
	{
		if (c == specifier[i])
			return (1);
		i++;
	}
	return (0);
}

int	print_specifier(char specifier, va_list arg)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (specifier == 'p')
		return (ft_add(va_arg(arg, void *)));
	if (specifier == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (specifier == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (specifier == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int)));
	if (specifier == 'x')
		return (ft_print_lower_digit((long)va_arg(arg, unsigned int), 16));
	if (specifier == 'X')
		return (ft_print_upper_digit((long)va_arg(arg, unsigned int), 16));
	if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && ft_specifier(str[i + 1]))
		{
			count += print_specifier(str[i + 1], arg);
			i++;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}
