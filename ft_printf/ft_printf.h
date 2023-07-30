/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidot <cvidot@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:48:50 by cvidot            #+#    #+#             */
/*   Updated: 2023/07/18 13:59:46 by cvidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(const char *s);
int	ft_print_char(char c);
int	ft_print_str(char const *s);
int	ft_print_nbr(int num);
int	ft_print_unnbr(unsigned int num);
int	ft_print_hex(unsigned int num, char format);
int	ft_print_ptr(void *ptr);

#endif
