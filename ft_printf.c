/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:03:55 by gaesteve          #+#    #+#             */
/*   Updated: 2024/02/04 18:33:48 by gaesteve         ###   ########.fr       */
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
		count += ft_print_hexa_lower(va_arg(args, int), 10);
	else if (specifier == 'i')
		count += ft_print_hexa_lower(va_arg(args, int), 10);
	else if (specifier == 'u')
		count += ft_print_hexa_lower(va_arg(args, unsigned int), 10);
	else if (specifier == 'x')
		count += ft_print_hexa_lower((long)va_arg(args, unsigned int), 16);
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

/*
int	main()
{
	int			integer;
	int			negative_integer;
	int			hexa;
	int			hexa_upper;
	char		character;
	char		*string;
	unsigned int	ptr;

	integer = 15925;
	negative_integer = -2147483648;
	hexa = 1968;
	hexa_upper = 1560;
	character = 'c';
	string = "123 test 456 test 789 test";
	ptr = 3546;

	ft_printf("mon test en int : %d\n", integer);
	printf("vrai test en int : %d\n\n", integer);
	ft_printf("mon test en int negatif : %d\n", negative_integer);
	printf("vrai test en int negatif : %d\n\n", negative_integer);
	ft_printf("mon test en char : %c\n", character);
    printf("vrai test en char : %c\n\n", character);
    ft_printf("mon test en string : %s\n", string);
    printf("vrai test en string : %s\n\n", string);
 	ft_printf("mon test en hexa lower : %x\n", hexa);
    printf("vrai test en hexa lower : %x\n\n", hexa);
    ft_printf("mon test en hexa upper: %X\n", hexa_upper);
    printf("vrai test en hexa upper : %X\n\n", hexa_upper);
    ft_printf("mon test en unsigned : %u\n", ptr);
    printf("vrai test en unsigned : %u\n\n", ptr);
}
*/
