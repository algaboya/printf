/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:50:23 by algaboya          #+#    #+#             */
/*   Updated: 2024/02/29 21:01:34 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_put_char(int c);
int	ft_put_low_hex(unsigned long long nbr);
int	ft_put_nbr_unsigned(unsigned long n);
int	ft_put_ptr(unsigned long long ptr);
int	ft_put_nbr(int n);
int	ft_put_str(char *ptr);
int	ft_put_up_hex(unsigned long long nbr);

#endif