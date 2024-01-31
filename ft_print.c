/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:30 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/31 11:36:32 by gaesteve         ###   ########.fr       */
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
	char	*base16;

	base16 = "0123456789abcdef";
	if (n < 0)
	{
		ft_print_char('-');
		return (ft_print_hexa_lower(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(base16[n]));
	else
	{
		count = ft_print_hexa_lower(n / base, base);
		return (count + ft_print_hexa_lower(n % base, base));
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
		return (count + print_hexa_upper(n % base, base));
	}
}

int	ft_print_ptr(void *ptr) // MODIFIER CETTE FONCTION.
{
	int	count;
	int	i;

}
