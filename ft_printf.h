/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:26:56 by gaesteve          #+#    #+#             */
/*   Updated: 2024/02/04 18:03:17 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
// Handling the printing tasks based on specifiers.

int	ft_print_specifier(char specifier, va_list arg);
// Calls the appropriate function to handle each specifier.

int	ft_print_char(int c);/* %c */
// print the specified character to the standard output.

int	ft_print_str(char *str);/* %s */
// print the entire string to the standard output.

int	ft_print_hexa_lower(long n, int base);/* %d - %i - %u - %x */
// print the hexa representation of a given integer in lowercase.

int	ft_print_hexa_upper(long n, int base);/* %X */
// print the hexa representation of a given integer in uppercase.

int	ft_print_ptr(unsigned long int *n, char *base);/* %p */
// print the hexa representation of a pointer using the base of chars.

#endif
