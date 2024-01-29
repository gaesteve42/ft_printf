/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:03:55 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/29 16:24:13 by gaesteve         ###   ########.fr       */
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
		return (ft_print_char(va_arg(arg, int)));
	if (specifier == 's')
		count += ft_print_str(va_arg(arg, char *));
	if (specifier == 'p')
		count += ft_print_ptr(va_arg(arg, void *));
	if (specifier == 'd')
		count += ft_print_min(va_arg(arg, int), 10);
	if (specifier == 'i')
		count += ft_print_min(va_arg(arg, int), 10);
	if (specifier == 'u')
		count += ft_print_min(va_arg(arg, unsigned int), 10);
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
/*
#include <stdio.h>
int	main()
{
	int testint;
	int	test_neg_int;
	int	testhexa;
	int testhexaup;
	char testchar;
	char *teststr;
	unsigned int	testu;

	testint = 142;
	test_neg_int = -2147483648;
	testhexa = 1968;
	testhexaup = 1968;
	testchar = 'c';
	teststr = "Salut Bg !";
	testu = 3435;

	ft_printf("test de ma fonction avec un int : %d\n", testint);
	printf("test de la vrai fonction avec un int : %d\n\n", testint);
    ft_printf("test de ma fonction avec un int neg : %d\n", test_neg_int);
    printf("test de la vrai fonction avec un int neg : %d\n\n", test_neg_int);
    ft_printf("test de ma fonction avec un char : %c\n", testchar);
    printf("test de la vrai fonction avec un char : %c\n\n", testchar);
    ft_printf("test de ma fonction avec une string : %s\n", teststr);
    printf("test de la vrai fonction avec une string : %s\n\n", teststr);
 	ft_printf("test de ma fonction avec un hexa : %x\n", testhexa);
    printf("test de la vrai fonction avec un hexa : %x\n\n", testhexa);
    ft_printf("test de ma fonction avec un hexa  upper: %X\n", testhexaup);
    printf("test de la vrai fonction avec un hexa upper : %X\n\n", testhexaup);
    ft_printf("test de ma fonction avec un decimal non signe : %u\n", testu);
    printf("test de la vrai ft avec un decimal non signe : %u\n\n", testu);
    int *ptr;
	int n;
	int count;
	ptr = &n;
	count = 0;
	printf("--Real printf\n");
	count += printf("%p\n", ptr);
	printf("%d\n", count);
	count = 0;
	printf("--My printf\n");
	count += ft_printf("%p\n", ptr);
	printf("%d\n", count);
	count = 0;
	printf("|| Null case || \n--Real printf\n");
	count += printf("%d\n", 0);
	printf("%d\n", count);
	count = 0;
	printf("My printf\n");
	count += ft_printf("%p\n", 0);
	printf("%d\n", count);
	count = 0;
}*/
