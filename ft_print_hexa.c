/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:15:21 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/23 18:34:45 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_digit(long n, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar('-');
		return (count + ft_print_upper_digit(-n, base));
	}
	else if (n < base)
		return (ft_putchar(hexa[n]));
	else
	{
		count = ft_print_upper_digit(n / base, base);
		return (count + ft_print_upper_digit(n % base, base));
	}
}

int	ft_print_lower_digit(long n, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		return (count + ft_print_lower_digit(-n, base));
	}
	else if (n < base)
		return (count + ft_putchar(hexa[n]));
	else
	{
		count = ft_print_lower_digit(n / base, base);
		return (count + ft_print_lower_digit(n % base, base));
	}
}
