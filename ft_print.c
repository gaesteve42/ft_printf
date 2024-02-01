/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:30 by gaesteve          #+#    #+#             */
/*   Updated: 2024/02/01 16:19:04 by gaesteve         ###   ########.fr       */
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

int	ft_print_hexa(long n, int base)
{
	int		count;
	char	*base16;

	base16 = "0123456789abcdef";
	if (n < 0)
	{
		ft_print_char('-');
		return (ft_print_hexa(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(base16[n]));
	else
	{
		count = ft_print_hexa(n / base, base);
		return (count + ft_print_hexa(n % base, base));
	}
}

int	ft_print_hexa_upper(long n, int base)
{
	int		count;
	char	*base16;

	count = 0;
	base16 = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_print_char('-');
		return (count + ft_print_hexa_upper(-n, base));
	}
	else if (n < base)
		return (ft_print_char(base16[n]));
	else
	{
		count = ft_print_hexa_upper(n / base, base);
		return (count + ft_print_hexa_upper(n % base, base));
	}
}

int	ft_print_ptr(unsigned long int *n, char *base)
{
	int					i;
	int					count;
	unsigned long int	number;
	char				tab[16];

	if (!n)
		return (ft_print_str("(nil)"));
	i = 0;
	count = 0;
	number = (size_t) n;
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
