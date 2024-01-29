/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:30 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/29 17:59:09 by gaesteve         ###   ########.fr       */
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

int	ft_print_min(long n, int base)
{
	int		count;
	char	*tab;

	tab = "0123456789abcdef";
	if (n < 0)
	{
		ft_print_char('-');
		return (ft_print_min(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(tab[n]));
	else
	{
		count = ft_print_min(n / base, base);
		return (count + ft_print_min(n % base, base));
	}
}

int	ft_print_maj(long n, int base)
{
	int		count;
	char	*tab;

	count = 0;
	tab = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_print_char('-');
		return (count + ft_print_maj(-n, base));
	}
	else if (n < base)
		return (ft_print_char(tab[n]));
	else
	{
		count = ft_print_maj(n / base, base);
		return (count + ft_print_maj(n % 16, base));
	}
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_print_str("0x0");
		return (count);
	}
	else
	{
		count += ft_print_str("0x");
		count += ft_print_min((unsigned long)ptr, 16);
		return (count);
	}
}
