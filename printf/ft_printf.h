/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:55:11 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/15 15:10:41 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
size_t	formats(char c, va_list av);

size_t	ft_putchar(int c);
void	ft_print_hex(long long unsigned int nb, char *base);
size_t	ft_hexlen(long long unsigned int nb);
void	ft_putnbr(int n);
void	ft_putnbru(unsigned int nb);

size_t	print_str(char *str);
size_t	print_ptr(void *p);
size_t	print_int(int nb);
size_t	print_unsigned(unsigned int nb);
size_t	print_hex(long long unsigned int nb, char c);

#endif