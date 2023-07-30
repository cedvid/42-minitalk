/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidot <cvidot@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:57:21 by cvidot            #+#    #+#             */
/*   Updated: 2023/07/22 16:34:59 by cvidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_format(const char *format, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (*format == 'c')
		printed_chars += ft_print_char(va_arg(args, int));
	if (*format == 's')
		printed_chars += ft_print_str(va_arg(args, char *));
	if (*format == 'd' || *format == 'i')
		printed_chars += ft_print_nbr(va_arg(args, int));
	if (*format == 'u')
		printed_chars += ft_print_unnbr(va_arg(args, unsigned int));
	if (*format == 'x' || *format == 'X')
		printed_chars += ft_print_hex(va_arg(args, unsigned int), *format);
	if (*format == 'p')
		printed_chars += ft_print_ptr(va_arg(args, void *));
	if (*format == '%')
		printed_chars += ft_print_char('%');
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int		printed_chars;
	va_list	args;

	va_start(args, format);
	printed_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_chars += check_format(format, args);
		}
		else
			printed_chars += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
