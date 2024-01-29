/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:30 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/29 14:36:11 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		count = 6;
		return (count);
	}
	while (str[i])
	{
		count += ft_print_char(str[i]);
		i++;
	}
	return (count);
}

int	ft_print_nbr(long n, int base)
{
	int		count;
	char	*base16;

	base16 = "0123456789abcdef";
	if (n < 0)
	{
		ft_print_char('-');
		return (ft_print_nbr(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(base16[n]));
	else
	{
		count = ft_print_nbr(n / base, base);
		return (count + ft_print_nbr(n % base, base));
	}
}

int	ft_print_hexa(long n, int base)
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

int	ft_print_ptr(void *ptr)
{
	unsigned long	pointer;
	int				count;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	pointer = (unsigned long)ptr;
	if (pointer >= 16)
	{
		count += ft_print_ptr((void *)(pointer / 16));
	}
	else
	{
		ft_print_str("0x");
		count = count + 2;
	}
	count += ft_print_char("0123456789abcdef"[pointer % 16]);
	return (count);
}
