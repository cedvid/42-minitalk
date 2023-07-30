/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidot <cvidot@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:02:24 by cvidot            #+#    #+#             */
/*   Updated: 2023/07/16 11:03:25 by cvidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char const *s)
{
	int		i;
	int		printed_chars;

	i = 0;
	if (!s)
		s = "(null)";
	printed_chars = ft_strlen(s);
	while (s[i])
	{
		ft_print_char(s[i]);
		i++;
	}
	return (printed_chars);
}
