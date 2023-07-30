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

void	ft_get_hex_str(uintptr_t ptr, char *hex_digits, int *hex_len)
{
	int		remainder;

	*hex_len = 0;
	while (ptr > 0)
	{
		remainder = ptr % 16;
		hex_digits[*hex_len] = remainder;
		ptr /= 16;
		(*hex_len)++;
	}
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	int_ptr;
	char		hex_digits[16];
	int			printed_chars;
	int			hex_len;

	printed_chars = 0;
	hex_len = 0;
	if (!ptr)
		return (ft_print_str("(nil)"));
	int_ptr = (uintptr_t)ptr;
	ft_get_hex_str(int_ptr, hex_digits, &hex_len);
	printed_chars += ft_print_str("0x");
	while ((hex_len - 1) >= 0)
	{
		printed_chars += ft_print_hex(hex_digits[hex_len - 1], 'x');
		hex_len--;
	}
	return (printed_chars);
}
