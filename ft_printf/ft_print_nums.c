/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidot <cvidot@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:04:10 by cvidot            #+#    #+#             */
/*   Updated: 2023/07/18 14:02:02 by cvidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_nbr(int num)
{
	int	printed_chars;

	printed_chars = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		printed_chars += ft_print_char('-');
		printed_chars += ft_print_nbr(-num);
	}
	else if (num > 9)
	{
		printed_chars += ft_print_nbr(num / 10);
		printed_chars += ft_print_nbr(num % 10);
	}
	else
		printed_chars += ft_print_char(num + '0');
	return (printed_chars);
}

int	ft_print_unnbr(unsigned int num)
{
	int	printed_chars;

	printed_chars = 0;
	if (num > 9)
	{
		printed_chars += ft_print_unnbr(num / 10);
		printed_chars += ft_print_unnbr(num % 10);
	}
	else
		printed_chars += ft_print_char(num + '0');
	return (printed_chars);
}

int	ft_convert_hex(int tmp, char format)
{
	if (format == 'X')
		return (tmp + 55);
	else
		return (tmp + 87);
	return (tmp);
}

int	ft_print_hex(unsigned int num, char format)
{
	int		i;
	int		tmp;
	int		printed_chars;
	char	hex_num[9];

	i = 0;
	printed_chars = 0;
	if (!num)
		return (ft_print_char('0'));
	while (num)
	{
		tmp = num % 16;
		if (tmp < 10)
			tmp += 48;
		else
			tmp = ft_convert_hex(tmp, format);
		hex_num[i++] = tmp;
		num /= 16;
	}
	while (i > 0)
		printed_chars += ft_print_char(hex_num[--i]);
	return (printed_chars);
}
