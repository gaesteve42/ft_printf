/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:30 by gaesteve          #+#    #+#             */
/*   Updated: 2024/02/04 18:33:58 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		count += ft_print_char(str[i]);
		i++;
	}
	return (count);
}

int	ft_print_hexa_lower(long n, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (n < 0)
	{
		ft_print_char('-');
		return (count + ft_print_hexa_lower(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(hexa[n]));
	else
	{
		count = ft_print_hexa_lower(n / base, base);
		return (count + ft_print_hexa_lower(n % base, base));
	}
}

int	ft_print_hexa_upper(long n, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_print_char('-');
		return (count + ft_print_hexa_upper(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(hexa[n]));
	else
	{
		count = ft_print_hexa_upper(n / base, base);
		return (count + ft_print_hexa_upper(n % base, base));
	}
}

int	ft_print_ptr(unsigned long int *ptr, char *base)
{
	int					i;
	int					count;
	unsigned long int	number;
	char				tab[16];

	if (!ptr)
		return (ft_print_str("(nil)"));
	i = 0;
	count = 0;
	number = (size_t) ptr;
	count = count + ft_print_str("0x");
	while (number > 0)
	{
		tab[i++] = base[number % 16];
		number /= 16;
	}
	while (i)
	{
		count = count + ft_print_char(tab[--i]);
	}
	return (count);
}
/*
ft_print_ptr function :

L.96 - //(size_t) is used to convert the pointer value ptr to the type size_t
in order to ensure proper handling and alignment of memory-related operations.

L.97 - //Print "0x" prefix for hexa numbers.

L.98 - //Convert 'number' to hexa, store each digit in the 'tab' array.

L.103 - //Print each digit stored in the 'tab' array in reverse order.
*/
