/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <gaesteve@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:26:56 by gaesteve          #+#    #+#             */
/*   Updated: 2024/01/25 08:36:35 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_print_min(long n, int base);

int	ft_print_maj(long n, int base);

int	ft_print_char(int c);

int	ft_print_str(char *str);

int	ft_print_nbr(long n, int base);

int	ft_print_ptr(void *ptr);

#endif
