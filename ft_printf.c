/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:03:55 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/29 18:22:01 by gaesteve         ###   ########.fr       */
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
		count += ft_print_ptr(va_arg(args, void *));
	else if (specifier == 'd')
		count += ft_print_min(va_arg(args, int), 10);
	else if (specifier == 'i')
		count += ft_print_min(va_arg(args, int), 10);
	else if (specifier == 'u')
		count += ft_print_min(va_arg(args, unsigned int), 10);
	else if (specifier == 'x')
		count += ft_print_min((long)va_arg(args, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_print_maj((long)va_arg(args, unsigned int), 16);
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

	testint = 17;
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
}
*/
