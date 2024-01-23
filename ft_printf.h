/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:26:56 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/23 18:34:39 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_print_lower_digit(long n, int base);

int	ft_print_upper_digit(long n, int base);

int	ft_putchar(int c);

int	ft_putstr(char *str);

int	ft_putnbr(int n);

int	ft_add(void *add);

int	ft_unsigned(unsigned int n);

#endif
