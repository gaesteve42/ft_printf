/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:03:55 by gaesteve          #+#    #+#             */
/*   Updated: 2024/02/01 16:18:50 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_specifier(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(args, void *), "0123456789abcdef");
	else if (specifier == 'd')
		count += ft_print_hexa(va_arg(args, int), 10);
	else if (specifier == 'i')
		count += ft_print_hexa(va_arg(args, int), 10);
	else if (specifier == 'u')
		count += ft_print_hexa(va_arg(args, unsigned int), 10);
	else if (specifier == 'x')
		count += ft_print_hexa((long)va_arg(args, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_print_hexa_upper((long)va_arg(args, unsigned int), 16);
	else if (specifier == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_print_specifier(str[i], args);
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
