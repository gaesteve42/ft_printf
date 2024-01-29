/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:03:55 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/29 14:36:14 by gaesteve         ###   ########.fr       */
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

int	ft_print_specifier(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(arg, int));
	if (specifier == 's')
		count += ft_print_str(va_arg(arg, char *));
	if (specifier == 'p')
		count += ft_print_ptr(va_arg(arg, void *));
	if (specifier == 'd')
		count += ft_print_nbr(va_arg(arg, int), 10);
	if (specifier == 'i')
		count += ft_print_nbr(va_arg(arg, int), 10);
	if (specifier == 'u')
		count += ft_print_nbr(va_arg(arg, unsigned int), 10);
	if (specifier == 'x')
		count += ft_print_min((long)va_arg(arg, unsigned int), 16);
	if (specifier == 'X')
		count += ft_print_maj((long)va_arg(arg, unsigned int), 16);
	if (specifier == '%')
		count += ft_print_char('%');
	return (count);
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
			count += ft_print_specifier(str[i + 1], arg);
			i++;
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
