/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:15:21 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/25 08:36:06 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_maj(long n, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_print_char('-');
		return (count + ft_print_maj(-n, base));
	}
	else if (n < base)
		return (ft_print_char(hexa[n]));
	else
	{
		count = ft_print_maj(n / base, base);
		return (count + ft_print_maj(n % 16, base));
	}
}

int	ft_print_min(long n, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (n < 0)
	{
		ft_print_char('-');
		return (count + ft_print_min(-n, base));
	}
	else if (n < base)
		return (count + ft_print_char(hexa[n]));
	else
	{
		count = ft_print_min(n / base, base);
		return (count + ft_print_min(n % base, base));
	}
}
