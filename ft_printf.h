/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:26:56 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/29 15:40:47 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_print_char(int c);

int	ft_print_str(char *str);

int	ft_print_nbr(long n, int base);

int	ft_print_hexa(long n, int base);

int	ft_print_ptr(void *ptr);

#endif
