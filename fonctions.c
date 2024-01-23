/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:30 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/23 18:39:55 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
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
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += write (1, "-2147483648", 11);
	else if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_unsigned(n / 10);
		count += ft_unsigned(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_add(void *add)
{
	int					i;
	int					count;
	char				*hexa;
	char				*adresse[16];
	unsigned long int	n;

	count = 0;
	if (!add)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	i = 0;
	n = (size_t) add;
	hexa = "0123456789abcdef";
	count += ft_putstr("0x");
	while (n > 0)
	{
		adresse[i++] = &hexa[n % 16];
		n /= 16;
	}
	while (i)
		count += ft_putchar(*adresse[--i]);
	return (count);
}
